/*******************************************************************************
  QSPI1 Peripheral Library Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_qspi1_spi.c

  Summary
    QSPI1 peripheral library interface when in SPI mode.

  Description

  Remarks:

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "plib_qspi1_spi.h"
#include "string.h" // memmove
#include "interrupts.h"

volatile static qspi_spi_obj qspiObj;

void QSPI1_Initialize(void)
{
    // Reset and Disable the qspi Module
    QSPI1_REGS->QSPI_CR = QSPI_CR_SWRST_Msk | QSPI_CR_QSPIDIS_Msk;

    while((QSPI1_REGS->QSPI_SR& QSPI_SR_QSPIENS_Msk) !=0U)
    {
        ;   // spin lock
    }

    /* DLYCS  = 0x0 */
    /* DLYBCT = 0x0 */
    /* NBBITS = 0x0 */
    /* LLB    = 0 */
    /* CSMODE = 0x0 */
    /* WDRBT  = 0 */
    /* SMM    = SPI */
    QSPI1_REGS->QSPI_MR = ( QSPI_MR_SMM_SPI | QSPI_MR_NBBITS(0x0U)  | QSPI_MR_LLB(0U) );

    /* CPOL = 0 */
    /* CPHA = 0 */
    /* SCBR = 10 */
    /* DLYBS = 0 */
    QSPI1_REGS->QSPI_SCR = (QSPI_SCR_SCBR(10U))  ;

    // Enable the qspi Module
    QSPI1_REGS->QSPI_CR = QSPI_CR_QSPIEN_Msk;

    while((QSPI1_REGS->QSPI_SR& QSPI_SR_QSPIENS_Msk) == 0U)
    {
        ;   // spin lock
    }
}

bool QSPI1_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;
    uint32_t dummyData;

    /* Verify the request */
    if((qspiObj.transferIsBusy == false) && (((txSize > 0U) && (pTransmitData != NULL)) || ((rxSize > 0U) && (pReceiveData != NULL))))
    {
        isRequestAccepted = true;
        qspiObj.txBuffer = pTransmitData;
        qspiObj.rxBuffer = pReceiveData;
        qspiObj.rxCount = 0;
        qspiObj.txCount = 0;
        qspiObj.dummySize = 0;
        if (pTransmitData != NULL)
        {
            qspiObj.txSize = txSize;
        }
        else
        {
            qspiObj.txSize = 0;
        }

        if (pReceiveData != NULL)
        {
            qspiObj.rxSize = rxSize;
        }
        else
        {
            qspiObj.rxSize = 0;
        }

        qspiObj.transferIsBusy = true;

        /* Flush out any unread data in SPI read buffer */
        dummyData = (QSPI1_REGS->QSPI_RDR & QSPI_RDR_RD_Msk) >> QSPI_RDR_RD_Pos;
        (void)dummyData;

        size_t txSz = qspiObj.txSize;

        if (qspiObj.rxSize > txSz)
        {
            qspiObj.dummySize = qspiObj.rxSize - txSz;
        }

        /* Start the first write here itself, rest will happen in ISR context */
        if((QSPI1_REGS->QSPI_MR & QSPI_MR_NBBITS_Msk) == QSPI_MR_NBBITS_8_BIT)
        {
            if (qspiObj.txCount < txSz)
            {
                QSPI1_REGS->QSPI_TDR = *((uint8_t*)qspiObj.txBuffer);
                qspiObj.txCount++;
            }
            else if (qspiObj.dummySize > 0U)
            {
                QSPI1_REGS->QSPI_TDR = (uint8_t)(0xff);
                qspiObj.dummySize--;
            }
            else
            {
                ; /* No action required - ; is optional */
            }
        }
        else if((QSPI1_REGS->QSPI_MR & QSPI_MR_NBBITS_Msk) == QSPI_MR_NBBITS_16_BIT)
        {
            qspiObj.txSize >>= 1;     /* divide by 2 since dealing with 2-byte quantities here */
            qspiObj.dummySize >>= 1;
            qspiObj.rxSize >>= 1;

            txSz = qspiObj.txSize;

            if (qspiObj.txCount < txSz)
            {
                QSPI1_REGS->QSPI_TDR = *((uint16_t*)qspiObj.txBuffer);
                qspiObj.txCount++;
            }
            else if (qspiObj.dummySize > 0U)
            {
                QSPI1_REGS->QSPI_TDR = (uint16_t)(0xff);
                qspiObj.dummySize--;
            }
            else
            {
                ; /* No action required - ; is optional */
            }
        }
        else
        {
            ; /* No action required - ; is optional */
        }

        if (rxSize > 0U)
        {
            /* Enable receive interrupt to complete the transfer in ISR context */
            QSPI1_REGS->QSPI_IER = QSPI_IER_RDRF_Msk;
        }
        else
        {
            /* Enable transmit interrupt to complete the transfer in ISR context */
            QSPI1_REGS->QSPI_IER = QSPI_IER_TDRE_Msk;
        }
    }

    return isRequestAccepted;
}

bool QSPI1_Write(void* pTransmitData, size_t txSize)
{
    return(QSPI1_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool QSPI1_Read(void* pReceiveData, size_t rxSize)
{
    return(QSPI1_WriteRead(NULL, 0, pReceiveData, rxSize));
}

bool QSPI1_IsTransmitterBusy(void)
{
    return ((QSPI1_REGS->QSPI_SR & QSPI_SR_TXEMPTY_Msk) == 0U)? true : false;
}

bool QSPI1_TransferSetup (QSPI_TRANSFER_SETUP * setup, uint32_t spiSourceClock )
{
    uint32_t scbr;
    bool setupStatus = false;
    if ((setup != NULL) && (setup->clockFrequency != 0U))
    {
    if(spiSourceClock == 0U)
    {
        // Fetch Master Clock Frequency directly
        spiSourceClock = 30181818;
    }

    scbr = spiSourceClock/setup->clockFrequency;

    if(scbr > 255U)
    {
        scbr = 255;
    }

    QSPI1_REGS->QSPI_SCR= (uint32_t)setup->clockPolarity | (uint32_t)setup->clockPhase | QSPI_SCR_SCBR(scbr);

    QSPI1_REGS->QSPI_MR = (QSPI1_REGS->QSPI_MR & ~QSPI_MR_NBBITS_Msk) | (uint32_t)setup->dataBits;

    setupStatus = true;
    }
    return setupStatus;
}

void QSPI1_CallbackRegister (QSPI_CALLBACK callback, uintptr_t context)
{
    qspiObj.callback = callback;
    qspiObj.context = context;
}

bool QSPI1_IsBusy(void)
{
    bool transferIsBusy = qspiObj.transferIsBusy;

    return (((QSPI1_REGS->QSPI_SR & QSPI_SR_TXEMPTY_Msk ) == 0U) || (transferIsBusy));
}

void __attribute__((used)) QSPI1_InterruptHandler(void)
{
    uint32_t dataBits ;
    uint32_t receivedData;
    size_t rxCount = qspiObj.rxCount;
    size_t txCount = qspiObj.txCount;
    size_t txSize = qspiObj.txSize;

    static bool isLastByteTransferInProgress = false;

    dataBits = QSPI1_REGS->QSPI_MR & QSPI_MR_NBBITS_Msk;

    /* See if there's received data (MOSI) to be processed */
    if ((QSPI1_REGS->QSPI_SR & QSPI_SR_RDRF_Msk ) == QSPI_SR_RDRF_Msk)
    {
        receivedData = (QSPI1_REGS->QSPI_RDR & QSPI_RDR_RD_Msk) >> QSPI_RDR_RD_Pos;

        if (rxCount < qspiObj.rxSize)
        {
            if(dataBits == QSPI_MR_NBBITS_8_BIT)
            {
                ((uint8_t*)qspiObj.rxBuffer)[rxCount] = (uint8_t)receivedData;
                rxCount++;
            }
            else
            {
                ((uint16_t*)qspiObj.rxBuffer)[rxCount] = (uint16_t)receivedData;
                rxCount++;
            }

            qspiObj.rxCount = rxCount;
        }
    }

    /* If there are more words to be transmitted, then transmit them here and keep track of the count */
    if((QSPI1_REGS->QSPI_SR & QSPI_SR_TDRE_Msk) == QSPI_SR_TDRE_Msk)
    {
        /* Disable the TDRE interrupt. This will be enabled back if more than
         * one byte is pending to be transmitted */
        QSPI1_REGS->QSPI_IDR = QSPI_IDR_TDRE_Msk;

        if(dataBits == QSPI_MR_NBBITS_8_BIT)
        {
            if (txCount < qspiObj.txSize)
            {
                QSPI1_REGS->QSPI_TDR = ((uint8_t*)qspiObj.txBuffer)[txCount];
                txCount++;
            }
            else if (qspiObj.dummySize > 0U)
            {
                QSPI1_REGS->QSPI_TDR = (uint8_t)(0xff);
                qspiObj.dummySize--;
            }
            else
            {
                ; /* No action required - ; is optional */
            }
        }
        else
        {
            if (txCount < qspiObj.txSize)
            {
                QSPI1_REGS->QSPI_TDR = ((uint16_t*)qspiObj.txBuffer)[txCount];
                txCount++;
            }
            else if (qspiObj.dummySize > 0U)
            {
                QSPI1_REGS->QSPI_TDR = (uint16_t)(0xff);
                qspiObj.dummySize--;
            }
            else
            {
                ; /* No action required - ; is optional */
            }
        }

        qspiObj.txCount = txCount;

        if ((qspiObj.dummySize == 0U) && (txCount == txSize))
        {
            /* At higher baud rates, the data in the shift register can be
             * shifted out and TXEMPTY flag can get set resulting in a
             * callback been given to the application with the SPI interrupt
             * pending with the application. This will then result in the
             * interrupt handler being called again with nothing to transmit.
             * To avoid this, a software flag is set, but
             * the TXEMPTY interrupt is not enabled until the very end.
             */

            isLastByteTransferInProgress = true;
            /* Set Last transfer to deassert NPCS after the last byte written in TDR has been transferred. */
            QSPI1_REGS->QSPI_CR = QSPI_CR_LASTXFER_Msk;
        }
        else if (rxCount == qspiObj.rxSize)
        {
            /* Enable TDRE interrupt as all the requested bytes are received
             * and can now make use of the internal transmit shift register.
             */
            QSPI1_REGS->QSPI_IDR = QSPI_IDR_RDRF_Msk;
            QSPI1_REGS->QSPI_IER = QSPI_IER_TDRE_Msk;
        }
        else
        {
            ; /* No action required - ; is optional */
        }
    }

    /* See if Exchange is complete */
    if ((isLastByteTransferInProgress == true) && ((QSPI1_REGS->QSPI_SR & QSPI_SR_TXEMPTY_Msk) == QSPI_SR_TXEMPTY_Msk))
    {
        if (rxCount == qspiObj.rxSize)
        {
            qspiObj.transferIsBusy = false;

            /* Disable TDRE, RDRF and TXEMPTY interrupts */
            QSPI1_REGS->QSPI_IDR = QSPI_IDR_TDRE_Msk | QSPI_IDR_RDRF_Msk | QSPI_IDR_TXEMPTY_Msk;

            isLastByteTransferInProgress = false;

            if(qspiObj.callback != NULL)
            {
                uintptr_t context = qspiObj.context;

                qspiObj.callback(context);
            }
        }
    }
    if (isLastByteTransferInProgress == true)
    {
        /* For the last byte transfer, the TDRE interrupt is already disabled.
         * Enable TXEMPTY interrupt to ensure no data is present in the shift
         * register before application callback is called.
         */
        QSPI1_REGS->QSPI_IER = QSPI_IER_TXEMPTY_Msk;
    }

}
/*******************************************************************************
 End of File
*/