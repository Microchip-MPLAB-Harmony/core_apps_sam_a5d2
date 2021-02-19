---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: FAT filesystem using SDMMC Media 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FAT filesystem using SDMMC Media

This application shows an example of using the MPLAB Harmony File System to access and modify the contents of a SD card using the SDMMC driver.

## Description

### File System Operations on the SD Card:

- Application opens a file named **FILE_TOO_LONG_NAME_EXAMPLE_123.JPG** in the root directory of the SD card and reads its content into memory
  - The image file could be any arbitrary JPEG (image) file chosen by the user and then renamed to **FILE_TOO_LONG_NAME_EXAMPLE_123.JPG**
- Application creates directory named **Dir1** in the root directory
- Application creates a new file named **FILE_TOO_LONG_NAME_EXAMPLE_123.JPG** inside **Dir1**
- Application copies the content from step 1 into this newly created file

The reason for choosing a JPEG file for test purposes is that the duplicate file, **Dir1/FILE_TOO_LONG_NAME_EXAMPLE_123.JPG** created by the demonstration could be easily verified for correctness.If the new file inside **Dir1** opens for viewing on the computer and matches to original image, the test is deemed to have passed. Otherwise, if the file does not open (i.e., is corrupted), the test will be considered to have failed.

### Note:

*Since the application creates a directory named Dir1, it is important that the a folder with the same name does not exist on the SD card. If a directory named Dir1 is already present on the SD card, the application will fail.*

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/fs/sdmmc_fat/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d27_som1_ek_freertos.X | MPLABX project for [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
| sam_a5d2_xult.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d2_xult_freertos.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d2_xult_freertos_iar.IAR/sdmmc_fat_sam_a5d2_xult_freertos.eww/sdmmc_fat_sam_a5d2_xult_freertos.eww | IAR project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d2_xult_iar.IAR/sdmmc_fat_sam_a5d2_xult.eww/sdmmc_fat_sam_a5d2_xult.eww | IAR project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult.X <br> sam_a5d2_xult_freertos.X <br> sam_a5d2_xult_freertos_iar.IAR/sdmmc_fat_sam_a5d2_xult_freertos.eww/sdmmc_fat_sam_a5d2_xult_freertos.eww <br> sam_a5d2_xult_iar.IAR/sdmmc_fat_sam_a5d2_xult.eww/sdmmc_fat_sam_a5d2_xult.eww | [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d27_som1_ek_freertos.X | [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
|||

### Setting up [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)

#### Addtional hardware required

- SD Card with FAT32 file system

#### Setting up the SD Card

- Download harmony MPU bootstrap loader from this [location](firmware/at91bootstrap_sam_a5d27_som1_ek_freertos.X/binaries/boot.bin)
- Copy the downloaded boot loader binary( boot.bin) onto the SD card
- Create a new JPEG file in the SD Card with name FILE_TOO_LONG_NAME_EXAMPLE_123.JPG

#### Setting up the board

- SDMMC slot used for bootloading the application is SDMMC1
- Connect the Debug USB port on the board to the computer using a micro USB cable

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

## Running the Application

1. Build the application using its IDE
2. Copy the output binary (named 'harmony.bin') onto the SD Card (Refer to the 'Setting up hardware' section above for setting up the SD card)
3. Insert the SD card into SDMMC slot on the board (Refer to the 'Setting up hardware' section for the correct SDMMC slot)
4. Reset the board to run the application
5. The LED is turned ON if there was no error during creating the directory and copying the file into it


Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)  | D5(Green) |
|  [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)  | RGB_LED(Green) |
|||