---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: FAT filesystem using SQI Flash Media 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FAT filesystem using SQI Flash Media

This application shows an example of using the MPLAB Harmony File System to access SQI based flash media. The SAMA5D2 Xplained Ultra Evaluation Kit has the MX25L flash memory while the SAMA5D27-SOM1-EK1 and the SAMA5D27-WLSOM1-EK1
have the SST26 flash media.

## Description

### File System Operations on the On-Board SQI Flash Memory

- Performs a SYS_FS_FormatDisk
- Opens a **newfile.txt** on the flash memory
- Write and reads back 4KB of data on **newfile.txt**
- Verifies the Data Read back

### File system layer uses the following components

- One instance of the Memory driver is used to communicate with the On-Board SQI Flash memory

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/fs/sqi_flash_fat/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d2_xult_freertos.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d27_som1_ek_freertos.X | MPLABX project for [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
| sam_a5d27_wlsom1_ek1_freertos.X | MPLABX project for [SAMA5D27-WLSOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320117) |
| 
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X <br> sam_a5d2_xult_freertos.X  | [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d27_som1_ek_freertos.X | [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
| sam_a5d27_wlsom1_ek1_freertos.X | [SAMA5D27-WLSOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320117) |
|||


### Setting up [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)
  
#### Setting up the board

- Short jumper JP2 (DEBUG_DIS)
- Connect a USB to UART FTDI cable to J1 (DEBUG) to open a serial terminal
- Connecting a micro-USB cable to either J23 or J14 powers the board

### Setting up [SAMA5D27-SOM1-EK1 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)


#### Setting up the board

- Connecting a micro-USB cable to J10 both powers the board as well as provides a virtal COM port to open a serial terminal

### Setting up [SAMA5D27-WLSOM1-EK1 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320117)


#### Setting up the board

- Connect a USB to UART FTDI cable to J26 (DEBUG FTDI) to open a serial terminal
- Connecting a micro-USB cable to J10 powers the board
- Press the SW3 (nSTART_SOM) button to power the ATSAMA5D27-WLSOM1 System-On-Module

## Running the Application

1. Build the application using its IDE
2. The LED is turned ON if data has successfully been written and read back from file "newfile.txt"

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)  | RGB LED(Green) |
|  [SAMA5D27-SOM1-EK1 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)  | D5 (Green) | 
|  [SAMA5D27-WLSOM1-EK1 Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320117)  | LD1 (Green) |
|
|||