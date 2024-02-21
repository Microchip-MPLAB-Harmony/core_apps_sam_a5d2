---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: SDSPI driver asynchronous - SDSPI Read Write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SDSPI driver asynchronous - SDSPI Read Write

This example application shows how to use the SDSPI driver in asynchronous mode to perform block operations on the SD Card Media.

## Description

This example uses the SDSPI driver in asynchronous mode. The asynchronous mode of the SDSPI driver performs non-blocking read and write operations. The SDSPI driver is configured to use DMA.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/sdspi/async/sdspi_read_write/firmware** .

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

- SD Card with FAT32 file system
- [Micro-SD click board](https://www.mikroe.com/microsd-click)

#### Setting up the board

- Insert SD Card in the [Micro-SD click board](https://www.mikroe.com/microsd-click) card slot. 
- Connect the [Micro-SD click board](https://www.mikroe.com/microsd-click) to MikroBus1 (J19) connector
- Connect the USB_A port on board to the computer using a USB-C type cable.

## Running the Application

1. Build and program the application using its IDE
2. The LED is turned ON when the read data from the SD card matches with the written data

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||