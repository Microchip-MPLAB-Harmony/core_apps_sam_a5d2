---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: SDMMC driver asynchronous - SDMMC Read Write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SDMMC driver asynchronous - SDMMC Read Write

This example application shows how to use the SDMMC driver in asynchronous mode to perform block operations on the SD Card Media.

## Description

- This example uses the SDMMC driver in asynchronous mode in both Bare-Metal and RTOS environment to perform Block Erase/Write/Read operations on SD-Card
- This application writes 60KB (61440 bytes) of data starting at the SD Card memory location 0x2000
- It then reads and verifies the written data

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/sdmmc/async/sdmmc_read_write/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult.X | MPLABX project for [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
| sam_a5d2_xult_freertos.X | MPLABX project for [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X <br> sam_a5d2_xult_freertos.X | [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

#### Setting up the board

- Connect the USB_A port on board to the computer using a USB-C type cable.
- Insert SD Card in µSD BOOT (J6) slot. SDMMC0 is configured for testing in application 

## Running the Application

1. Build and program the application using its IDE
2. The LED is turned ON when the read data from the SD Card matches with the written data

*NOTE: This demo application performs a raw read-write operation on the SD card. This causes the partition information to be overwritten causing the SD card file system to be corrupted. Hence resetting the board will not re-run the application demo (Board will fail to boot since it cannot find a valid partition). To repeat the demo we need to reformat SD card and prepare it as defined by the hardware setup.*

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||