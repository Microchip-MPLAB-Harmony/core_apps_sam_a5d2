# Harmony 3 Driver and System Service Application Examples for SAMA5D2 Family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware<br /> solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.<br /> Refer to the following links for more information.

-   [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
-   [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
-   [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
-   [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
-   [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 driver and system service application<br /> examples for SAMA5D2 family:

-   [Release Notes](docs/GUID-4561216B-E205-4AFF-A17F-6D221625C1B3.md)
-   [MPLAB® Harmony License](docs/GUID-5AE41BEF-D04E-41F6-AA77-5469CF13B183.md)

To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click **Clone**<br /> button to clone this repository or download as zip file. This content can also be<br /> downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

## Contents Summary

|Folder|Description|
|:-----|:----------|
|apps|Contains driver and system service<br /> example applications|
|docs|Contains documentation in html<br /> format for offline viewing \(to be used only after cloning this<br /> repository onto a local machine\). Use [github pages](https://microchip-mplab-harmony.github.io/) of this repository for<br /> viewing it online.|

## Code Examples

The following applications are provided to demonstrate the typical or interesting<br /> usage models of one or more peripheral libraries.

|Name|Description|
|----|-----------|
|[FAT Filesystem throughput using SDMMC Media](docs/GUID-98DA51A6-0573-4B85-8DD6-24B5B173AEFD.md)|This<br /> application calculates throughput by Writing and Reading data<br /> into a SD-Card at High Speed using the MPLAB Harmony File System<br /> and the SDMMC driver|
|[FAT Filesystem using SDMMC Media](docs/GUID-8B8C481F-C52A-4FFB-8423-31050111B7A6.md)|This<br /> application shows an example of using the MPLAB Harmony File<br /> System to access and modify the contents of a SD card using the<br /> SDMMC driver|
|[FAT Filesystem using SQI Flash Media](docs/GUID-6D54AB42-9777-4226-9410-0D7016F12099.md)|This<br /> application shows an example of using the MPLAB Harmony File<br /> System to access SQI based flash media. The SAMA5D29 Curiosity,<br /> SAMA5D27-SOM1-EK1 and the SAMA5D27-WLSOM1-EK1 has SST26 QSPI<br /> Flash|
|[FreeRTOS Basic](docs/GUID-61F2733C-6850-47F3-9E09-09858EDBA632.md)|This<br /> example application demonstrates context switching between four<br /> tasks of different priorities. Two tasks run periodically while<br /> the other two tasks are event driven|
|[FreeRTOS Task Notification](docs/GUID-36482548-254F-4BEF-9B3A-EB6304C2177E.md)|This<br /> example application is to illustrate the FreeRTOS Task<br /> Notification feature which is used as a light weight binary<br /> semaphore|
|[I2C Driver Asynchronous - I2C EEPROM](docs/GUID-9477DC36-3A77-4293-B9BA-05F9EE266700.md)|This<br /> example application shows how to use the I2C driver in<br /> asynchronous mode to perform operations on the EEPROM|
|[I2C Driver Synchronous - I2C EEPROM](docs/GUID-0454EEA2-4161-4582-91D6-A36BD0ED1DB3.md)|This<br /> example application shows how to use the I2C driver in<br /> synchronous mode to perform operations on the EEPROM|
|[I2C EEPROM AT24 Driver - EEPROM Read Write](docs/GUID-FE4ED785-299B-451D-9504-541051FD4A6A.md)|This<br /> example application shows how to use the AT24 driver to perform<br /> read and write operations on AT24 series of EEPROM|
|[Memory Driver Asynchronous - SST26 QSPI Flash Read Write](docs/GUID-65031C6B-6C5E-42D4-A6E8-366F5B812EA2.md)|This<br /> example application shows how to use the Memory driver in<br /> asynchronous mode to perform block operations on the SST26 QSPI<br /> flash media|
|[Memory Driver Synchronous - SST26 QSPI Flash Read Write](docs/GUID-250763EA-8D9A-4256-9A4B-AAFBF0496481.md)|This<br /> example application shows how to use the Memory driver in<br /> synchronous mode to perform block operations on the SST26 QSPI<br /> flash media|
|[SDMMC Driver Asynchronous - SDMMC Read Write](docs/GUID-F96B2372-1E69-4DE6-8426-FBDFDDEA7060.md)|This<br /> example application shows how to use the SDMMC driver in<br /> asynchronous mode to perform block operations on the SD Card<br /> Media|
|[SDSPI Driver Asynchronous - SDSPI Read Write](docs/GUID-4D539B63-2E39-463F-9910-18A53BFA8A8D.md)|This<br /> example application shows how to use the SDSPI driver in<br /> asynchronous mode to perform block operations on the SD Card<br /> Media|
|[SDSPI Driver Synchronous - SDSPI Read Write](docs/GUID-BFD23A8D-9E22-4764-B6B4-4E5A42DA1E50.md)|This<br /> example application shows how to use the SDSPI driver in<br /> synchronous mode to perform block operations on the SD Card<br /> Media|
|[SPI Driver Asynchronous - Multi Client](docs/GUID-169E5E38-4008-460A-837D-49B58F1241F9.md)|This<br /> example demonstrates how to use single instance of the SPI<br /> driver in asynchronous mode to communicate with multiple<br /> EEPROMs|
|[SPI Driver Asynchronous - Self Loopback Multi Client](docs/GUID-FF84624D-3175-4D24-8051-4534ED12FBC2.md)|This<br /> example demonstrates how to use the SPI driver in asynchronous<br /> mode to achieve self-loop back between multiple clients|
|[SPI Driver Synchronous - Multi Client](docs/GUID-D601CB3D-D4DD-4749-B5B0-F6AFD36B9F4D.md)|This<br /> example demonstrates how to use single instance of the SPI<br /> driver in synchronous mode to communicate with multiple EEPROMs<br /> in an RTOS environment|
|[SPI Driver Synchronous - Self Loopback Multi Client](docs/GUID-4C16F9F8-D1C2-4CF9-BF51-C3676AE5CB64.md)|This<br /> example demonstrates how to use the SPI driver in synchronous<br /> mode to achieve self-loop back between multiple clients in RTOS<br /> environment|
|[SPI EEPROM AT25 Driver - EEPROM Read Write](docs/GUID-0FCC44FB-2C32-4589-B4D5-EC80DD1A661E.md)|This<br /> example application shows how to use the AT25 driver to perform<br /> read and write operations on AT25 series of EEPROM|
|[SST26 SQI Flash Driver - Flash read write in SPI mode](docs/GUID-3E06296F-05F1-4C95-8EAF-FA39A56A9B39.md)|This<br /> example application shows how to use the AT25DF SPI flash driver<br /> to perform block operations on the on-board SST26 Flash memory<br /> in SPI mode|
|[SST26 SQI flash driver - Flash read write in SQI mode](docs/GUID-EA38B7D9-7652-4914-96EF-911C7D156CAC.md)|This<br /> example application shows how to use the SST26 QSPI flash driver<br /> to perform block operations on the on-board SST26 QSPI Flash<br /> memory|
|[Time System Service Multi-client](docs/GUID-0AED910A-890E-46A3-918D-0DD7377C4511.md)|This<br /> example application demonstrates the multi-client system timer<br /> functionality|
|[USART Driver Asynchronous - USART Echo](docs/GUID-8DECF40A-9B5F-4364-8326-EB36369751E3.md)|This<br /> example echoes the received characters over the console using<br /> the USART driver in asynchronous mode|
|[USART Driver Asynchronous - USART Multi Instance](docs/GUID-E289B497-06DA-4A04-8A16-4F2BAB13B0D9.md)|This<br /> example echoes the received characters over the two consoles<br /> using the USART driver in asynchronous mode|
|[USART Driver Synchronous - USART Echo](docs/GUID-06F2EB03-1FA3-49C0-95F7-150DB74CE380.md)|This<br /> example echoes the received characters over the console using<br /> the USART driver in synchronous mode|
|[USART Driver Synchronous - USART Multi Instance](docs/GUID-3C0ED229-BBF8-4182-8055-21A9182E970F.md)|This<br /> example echoes the received characters over the two consoles<br /> using the USART driver in synchronous mode|

