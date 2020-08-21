[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Time System Service multi-client

This example application demonstrates the multi-client system timer functionality.

## Description

- This application demonstrates timer functionality (with two clients to the Time System Service) by periodically printing a message on console every two seconds and blinking an LED every one second

- Delay, counter and single shot timer functionality is demonstrated on a switch press

- On a switch press, the application reads the current value of the 64 bit counter (say, count 1)
- It then starts a delay of 500 milliseconds and waits for the delay to expire
- Once the delay has expired, the application again reads the current value of the 64 bit counter (say, count 2) and calculates the difference between the two counter values

- The difference count indicates the time spent for the delay and is printed on the console as, "Delay time = x ms", where x is the delay value and is equal to 500 milliseconds in the given example

- The application then starts a single shot timer of 100 milliseconds
- When the single shot timer expires, a message is printed on the console that says "Single shot timer of 100 ms expired"
- This message is printed only once on every switch press

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_sam_a5d2) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/system/time/sys_time_multiclient/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_a5d27_som1_ek_freertos.X | MPLABX project for [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
| sam_a5d2_xult_freertos.X | MPLABX project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d2_xult_freertos_iar.IAR | IAR project for [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_a5d2_xult_freertos.X <br> sam_a5d2_xult_freertos_iar.IAR | [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT) |
| sam_a5d27_som1_ek_freertos.X | [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1) |
|||

### Setting up [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)

#### Addtional hardware required

- SD Card with FAT32 file system

#### Setting up the SD Card

- Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin)
- Copy the downloaded boot loader binary( boot.bin) onto the SD card

#### Setting up the board

- SDMMC slot used for bootloading the application is SDMMC1
- Connect the Debug USB port on the board to the computer using a micro USB cable

### Setting up [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)

#### Addtional hardware required

- SD Card with FAT32 file system

#### Setting up the SD Card

- Download harmony MPU bootstrap loader from this [location](https://github.com/Microchip-MPLAB-Harmony/at91bootstrap/blob/master/boot.bin)
- Copy the downloaded boot loader binary( boot.bin) onto the SD card

#### Setting up the board

- SDMMC slot used for bootloading the application is SDMMC1
- Short jumper JP2 (DEBUG_DIS)
- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build the application using its IDE
2. Copy the output binary (named 'harmony.bin') onto the SD Card (Refer to the 'Setting up hardware' section above for setting up the SD card)
3. Insert the SD card into SDMMC slot on the board (Refer to the 'Setting up hardware' section for the correct SDMMC slot)
4. Open the Terminal application (Ex.:Tera term) on the computer.
5. Connect to the EDBG/Jlink Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
6. Reset the board to run the application
7. Observe the following message getting printed on the console every two seconds

    ![output_sys_time_multiclient_1](images/output_sys_time_multiclient_1.png)

8. Press the switch and observe the following output on the terminal (highlighted in red box)

    ![output_sys_time_multiclient_2](images/output_sys_time_multiclient_2.png)

    - "Delay time = 500 ms" indicates the amount of time spent during the delay
    - "Single shot timer of 100 ms expired" is printed only once on every switch press

9. LED indicates the periodic timer functionality
    - LED is toggled periodically every one second

Refer to the following table for switch and LED name:

| Board | Switch Name | LED Name |
| ----- | ----------- | -------- |
|  [SAMA5D27-SOM1-EK1](https://www.microchip.com/DevelopmentTools/ProductDetails/atsama5d27-som1-ek1)  | USER | D5(Blue) |
|  [SAMA5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMA5D2C-XULT)  | PB_USER | RGB_LED(Blue) |
||||
