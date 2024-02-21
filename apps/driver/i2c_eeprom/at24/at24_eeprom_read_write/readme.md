---
parent: Harmony 3 driver and system service application examples for SAM A5D2 family
title: I2C EEPROM AT24 driver - EEPROM Read Write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# I2C EEPROM AT24 driver - EEPROM Read Write

This example application shows how to use the AT24 driver to perform read and write operations on AT24 series of EEPROM.

## Description

- This example uses the AT24 driver to communicate with I2C based External AT24CM0 series EEPROMs to perform write and read operations in Bare-Metal/ RTOS environment.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/i2c_eeprom/at24/at24_eeprom_read_write/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d2_curiosity.X | MPLABX project for [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
| sam_a5d2_curiosity_freertos.X | MPLABX project for [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

## Setting up AT91Bootstrap loader

To load the application binary onto the target device, we need to use at91bootstrap loader. Refer to the [at91bootstrap loader documentation](../../../../docs/readme_bootstrap.md) for details on how to configure, build and run bootstrap loader project and use it to bootstrap the application binaries.

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_curiosity.X <br> sam_a5d2_curiosity_freertos.X | [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |
|||

### Setting up [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A)

#### Addtional hardware required

- One [EEPROM 3 Click](https://www.mikroe.com/eeprom-3-click) board


#### Setting up the board

- Connect the USB_A port on board to the computer using a USB-C type cable
- Connect EEPROM Click 3 Board to MikroBus1 (J19) connector on the board as per below Pin Connections table

| J19 MikroBus1 Pins | EEPROM 3 CLICK Pins |
| -------------------- | ------------------- |
| PIN 11 (PD4) | SDA |
| PIN 12 (PD5) | SCL |
| PIN 19 | GND |
| PIN 20 | 3V3 |
|||

## Running the Application

1. Build the application using its IDE
2. LED indicates the success or failure:
    - LED is turned ON when the value read from the EEPROM matched with the written value
    - LED is turned OFF when the value read from the EEPROM did not match with the written value

Following table provides the LED name:

| Board      | LED Name                                    |
| ----------------- | ---------------------------------------------- |
| [SAMA5D29 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV07R15A) |RGB_LED(Green)  |
|||
