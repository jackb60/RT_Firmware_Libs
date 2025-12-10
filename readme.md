# **RT Firmware Libs**

## **GPS library**

### `GPS(HardwareSerial* gpsSer)`
constructor
### `void setup()`
begins serial port
### `void updateAndParse()`
moves any available serial data into the data buffer, and if any data is available, parses the buffer
### `float getPDOP()`
returns PDOP
### `float getVDOP()`
returns VDOP
### `float getHDOP()`
returns HDOP
### `float getLatitude()`
returns latitude
### `float getLongitude()`
returns longitude
### `float getAltitude()`
returns altitude in meters
### `bool getFix()`
returns true if GPS fix; false otherwise