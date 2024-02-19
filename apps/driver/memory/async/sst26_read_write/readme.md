---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: Memory driver asynchronous -  SST26 QSPI flash read write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Memory driver asynchronous -  SST26 QSPI Read Write

This example application shows how to use the Memory driver in in asynchronous mode of operation in both RTOS and Bare-Metal environment on the SST26 QSPI flash media.

## Description

This application uses multi instances of the Memory driver to communicate with the SST26 QSPI flash memories in asynchronous mode of operation in Bare-Metal environment.

It performs block Erase/Write/Read operations on both the media.

The application consists of three tasks which are called through the SYS_Tasks() routine in Bare-Metal environment and though RTOS thread context in RTOS environment.

**DRV_MEMORY_0_Tasks()** : Manages the state machine of the Memory driver instance 0.
**APP_SST26_Tasks()** : Performs operations on the SST26 QSPI flash memory.
**APP_MONITOR_Tasks()**: Monitors the state of above Task.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/memory/async/sst26_read_write/firmware** .

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

- Connect the USB_A port on board to the computer using a USB-C type cable.
- Make sure that the jumper J10 is connected 

## Running the Application

1. Build and program the application using its IDE
2. LED is turned ON when the data read from each media matches with the data written in them

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Curiosity Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||