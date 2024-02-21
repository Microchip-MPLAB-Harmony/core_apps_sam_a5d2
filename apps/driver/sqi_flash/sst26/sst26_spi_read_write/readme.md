---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: SST26 SQI flash driver - Flash read write in SPI mode 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SST26 SQI flash driver - Flash read write in SPI mode

This example application shows how to use the SST26 driver to perform block operations on the On-Board SST26 Flash memory in SPI mode.

## Description

This application uses the SST26 driver to Erase/Write/Read on the On-Board SST26 Flash memory using the SQI peripheral library configured in SPI mode.

The application consists of APP_SST26_Tasks() which is called through SYS_Tasks() routine.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/sqi_flash/sst26/sst26_spi_read_write/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
|  sam_a5d2_curiosity.X | MPLABX project for [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_curiosity.X | [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

- Connect the SQI Boot Jumper (J10).
- Connect the Debug USB port on the board to the computer using a USB-C cable

## Running the Application

1. Build and program the application using its IDE
2. LED is turned ON when the data read from SST26 flash matches with the data written in it

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)  | RGB_LED(Green) |
|||