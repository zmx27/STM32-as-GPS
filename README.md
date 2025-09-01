# STM32-as-GPS
Interfacing a GPS module with a STM32F401RE Nucleo Board to find the location coordinates and display them on a LCD display

# Nucleo F401RE GPS Tracker with LCD

This project demonstrates how to build a GPS tracking system using a **Nucleo F401RE** microcontroller, a **GY-NEO6MV2 GPS module**, and an **I2C 16x2 LCD display**. The system acquires location data (latitude and longitude) from the GPS module and displays it on the LCD screen.



## 📋 Components Required

* **Nucleo-F401RE** Microcontroller Board
* **GY-NEO6MV2** GPS Module
* **16x2 I2C LCD** Display Module
* Breadboard
* Jumper Wires
* Mini-USB Cable

***

## 🔌 Hardware Connections

All components are powered from the Nucleo board's 5V pin. The I2C protocol is used for the LCD, and the hardware serial port (`Serial1`) using the USART communication protocol is used for the GPS module.

### GPS Module Connections

The GPS module communicates with the Nucleo board using a serial connection. The Nucleo's `Serial1` pins (PA9/TX and PA10/RX) are used for this.

* **GPS VCC** → Nucleo **5V**
* **GPS GND** → Nucleo **GND**
* **GPS TXD** (Transmit) → Nucleo **PA10** (Receive)
* **GPS RXD** (Receive) → Nucleo **PA9** (Transmit)

### I2C LCD Connections

The LCD display communicates with the Nucleo board via the I2C protocol, which uses dedicated SDA and SCL pins.

* **LCD VCC** → Nucleo **5V**
* **LCD GND** → Nucleo **GND**
* **LCD SDA** → Nucleo **PB9**
* **LCD SCL** → Nucleo **PB8**

***

## 💻 Software Setup

### 1. Arduino IDE

Make sure you have the Arduino IDE installed and configured for the Nucleo board. You need to have the **STM32 Cores** installed through the Boards Manager.

### 2. Required Libraries

This project requires two libraries, which can be installed directly from the Arduino IDE's Library Manager.

1.  **TinyGPSPlus**: Used to parse the NMEA data coming from the GPS module.
    * Go to `Sketch` > `Include Library` > `Manage Libraries...`
    * Search for "TinyGPSPlus" and install the library by Mikal Hart.
2.  **LiquidCrystal_I2C**: Used to control the I2C LCD display.
    * Go to `Sketch` > `Include Library` > `Manage Libraries...`
    * Search for "LiquidCrystal I2C" and install the library by Frank de Brabander.

***

## 🚀 Code and Upload

The provided code reads data from the GPS module, checks for a valid satellite fix, and then displays the latitude and longitude on the LCD screen.

## ⚠️ Troubleshooting

1. LCD Not Working: Ensure the I2C address in the code (``0x27``) matches your LCD module. If not, try ``0x3F``.

2. "Waiting..." Loop: This is the expected behavior if the GPS module has not acquired a satellite fix.

3. No Satellite Fix: Place the GPS module outdoors with a clear view of the sky. The initial fix can take 15-30 minutes or longer in urban areas.
