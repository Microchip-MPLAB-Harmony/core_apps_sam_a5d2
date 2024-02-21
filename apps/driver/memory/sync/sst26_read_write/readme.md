---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: Memory driver synchronous - SST26 Read Write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Memory driver synchronous - SST26 Read Write

This example application shows how to use the Memory driver in synchronous mode to perform block operations on the SST26 media's.

## Description

### This application:

- Uses multi instances of the Memory driver to communicate with the SST26 Flash memories in synchronous mode of operation in RTOS Environment.

- Performs block Erase/Write/Read operations 

- Consists of two tasks which are called in the RTOS thread context:
    1. **APP_SST26_Tasks():**
        - Performs operations on the SST26 QSPI/SQI Flash Memory
    2. **APP_MONITOR_Tasks():**
        - Monitors the state of above Task

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/memory/sync/sst26_read_write/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_curiosity_freertos.X | MPLABX project for [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_curiosity_freertos.X | [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

- Connect the USB_A port on board to the computer using a USB-C type cable.
- Make sure that the jumper J10 is connected 

## Running the Application

1. Build and program the application using its IDE.
2. The LED blinks when the data read from memory matches with the data written in it.

Refer to the following table for LED name:

| Board | LED |
| ----- | -------- |
| [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) | RGB_LED(Green) |
|||
