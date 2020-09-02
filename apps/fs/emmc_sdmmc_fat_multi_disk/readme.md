---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: FAT filesystem using EMMC media 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FAT filesystem using EMMC media

This application shows an example of using the FAT filesystem to access and modify the contents of a eMMC device using contents from SD card.

## Description

Following file system operations are performed by this application:

- Application reads a file with name FILE_TOO_LONG_NAME_EXAMPLE_123.JPG in the root directory of SD-card media
- Application then creates a new directory in the root directory of EMMC media with the name Dir1
- Application creates a new file in the directory Dir1 in the eMMC media with name FILE_TOO_LONG_NAME_EXAMPLE_123.JPG
- Application writes the content it read from step 1 into the newly created file
- Application creates a new directory in root directory of the SD Card filesystem
- Application copies the file (by following steps above) from eMMC/Dir1 to sdcard/Dir1

The reason for choosing a JPEG file for test purposes is that the duplicate file, Dir1/FILE_TOO_LONG_NAME_EXAMPLE_123.JPG created by the demonstration could be easily verified for correctness.

If the new file inside Dir1 opens for viewing on the computer and matches to original image, the test is deemed to have passed. Otherwise, if the file does not open (i.e., is corrupted), the test will be considered to have failed.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/fs/emmc_sdmmc_fat_multi_disk/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_xult.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X | [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
|||

### Setting up [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)

#### Addtional hardware required

- SD Card with FAT32 file system

#### Setting up the SD Card

- Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_a5d2_xult.X/binaries/boot.bin)
- Copy the downloaded boot loader binary( boot.bin) onto the SD card
- Create a new JPEG file in the SD Card with name FILE_TOO_LONG_NAME_EXAMPLE_123.JPG

#### Setting up the board

- SDMMC slot used for bootloading the application is SDMMC1
- Short jumper JP2 (DEBUG_DIS)
- Connect the Debug USB port on the board to the computer using a micro USB cable
- Jumper JP9 (BOOT_DIS) should be open

## Running the Application

1. **NOTE: To run this demo successfully, on board eMMC device should have a valid FAT partition**
2. Build the application using its IDE
3. Copy the output binary (named 'harmony.bin') onto the SD Card (Refer to the 'Setting up hardware' section above for setting up the SD card)
4. Insert the SD card into SDMMC slot on the board (Refer to the 'Setting up hardware' section for the correct SDMMC slot)
5. Reset the board to run the application
6. The LED is turned ON if there was no error during creating the directory and copying the file into it

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)  | RGB_LED(Green) |
|||
