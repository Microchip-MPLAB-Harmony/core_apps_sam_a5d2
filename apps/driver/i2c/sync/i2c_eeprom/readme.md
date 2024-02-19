---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: I2C Driver Synchronous - I2C EEPROM 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# I2C Driver Synchronous - I2C EEPROM

This example application demonstrates how to use the I2C driver in synchronous mode to perform read/write operations on an EEPROM.

## Description

This example uses the I2C driver in synchronous mode to communicate with an EEPROM to perform read and write operations.

The application communicates with the [EEPROM 3 click board](https://www.mikroe.com/eeprom-3-click) that has AT24CM02 EEPROM on it.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/i2c/sync/i2c_eeprom/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult_freertos.X | MPLABX project for [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult_freertos.X | [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

- To run the demo, the following additional hardware are required:
    - [EEPROM 3 click board](https://www.mikroe.com/eeprom-3-click)

### Setting up [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

- Connect the [EEPROM 3 click board](https://www.mikroe.com/eeprom-3-click) to the MikroBus1 (J19) header of the [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)
- Connect the USB_A port on board to the computer using a USB-C type cable.

## Running the Application

1. Build and program the application using its IDE.
2. The LED indicates the success or failure.
    - The LED is turned ON when the data read from EEPROM matches with the written data

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) | RGB_LED(Green) |
|||