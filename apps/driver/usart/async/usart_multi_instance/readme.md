---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: USART driver asynchronous - USART multi instance 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# USART driver asynchronous - USART multi instance

This example echoes the received characters over the two consoles using the USART driver in asynchronous mode.

## Description

This example uses the USART driver in asynchronous mode in both Bare-Metal and RTOS environments to communicate over two consoles. It receives and echoes back the characters entered by the user on the respective console.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/usart/async/usart_multi_instance/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult.X | MPLABX project for [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X | [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

#### Addtional hardware required

- [USB UART CLICK](https://www.mikroe.com/usb-uart-click) board

#### Setting up the board

- Connect a FTDI cable from UART Debug (J28) port to computer.
- Connect [USB UART CLICK](https://www.mikroe.com/usb-uart-click) board to the curiosity board using the pin connections described below:

    | SAM A5D2 curiosity board Pins 	 | USB UART Click board Pins  |
    | ---------------------------------- | -------------------------- |
    | PIN 5, J8 connector                | RX                         |
    | PIN 4, J8 connector                | TX                         |
    | PIN 7, J19 connector               | 3.3V                       |
    | PIN 1, J8 connector                | GND                        |

- Connect the USB_A port on board to the computer using a USB-C type cable

## Running the Application

1. Build the application using its IDE
2. Open the Terminal application (Ex.:Tera term) on the computer for both ports
3. Connect to the Virtual COM ports and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
4. Type a character and observe the output on the two consoles as shown below:
    - If success the character typed echoes back and an LED toggles on each time the character is echoed
    - **Console 1**

    ![output_async_usart_multi_instance_console_1](./images/output_async_usart_multi_instance_console_1.png)

    - **Console 2**

    ![output_async_usart_multi_instance_console_2](./images/output_async_usart_multi_instance_console_2.png)

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||
