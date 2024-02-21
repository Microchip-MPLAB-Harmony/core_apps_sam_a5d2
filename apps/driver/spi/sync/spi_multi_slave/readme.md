---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: SPI Driver synchronous - multi client 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SPI Driver synchronous - multi client

This example demonstrates how to use single instance of the SPI driver in synchronous mode to communicate with multiple EEPROMs in an RTOS environment.

## Description

This example writes and reads data to and from two separate EEPROMs connected over the same SPI bus by using the multi client feature of a synchronous SPI driver. The example also demonstrates how to setup two different client transfers at two different baud rates.

The example has three RTOS threads for the purpose:

- **APP_EEPROM1_Tasks**: This thread performs write-read operation on the first EEPROM
- **APP_EEPROM2_Tasks**: This thread performs write-read operation on the second EEPROM
- **APP_MONITOR_Tasks**: This thread checks the status of the EEPROM transfers and turns on the LED if the transfers are successful

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/spi/sync/spi_multi_slave/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_curiosity_freertos.X | MPLABX project for [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_curiosity_freertos.X | [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

#### Addtional hardware required

- Two [EEPROM 4 Click](https://www.mikroe.com/eeprom-4-click) boards

#### Setting up the board

- Install [EEPROM 4 Click](https://www.mikroe.com/eeprom-4-click) boards on to the "MikroBus1 (J19)" and "MikroBus2 (J22)" connectors
- Connect the USB_A port on board to the computer using a USB-C type cable.

## Running the Application

1. Build and program the application using its IDE
2. The LED turns ON when the data read from the EEPROMs matches with the data written to the EEPROMs.

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||