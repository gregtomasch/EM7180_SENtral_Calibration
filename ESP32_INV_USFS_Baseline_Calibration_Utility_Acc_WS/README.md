# ESP32 and Invensense USFS
Interconnection of the USFS to the ESP32 development board is simple. The information given here is valid for the [Pesky Products ESP32](https://www.tindie.com/products/onehorse/smallest-esp32-development-board/) development board. However, the pinouts can be adjusted in the "config.h" tab of the sketch to interconnect with any other ESP32 developmnet board supported by the [Arduino core](https://github.com/espressif/arduino-esp32).

![alt text](https://user-images.githubusercontent.com/5760946/53356748-f83ba900-38e0-11e9-8e59-4dbb4f8317be.png)

For testing on a prototyping ["Breadboard"](https://cdn-shop.adafruit.com/1200x900/443-00.jpg) the interconnection matrix is:

## Prototype Breadboard
| USFS Pin |STM32Dev Board Pin|
|:--------:|:----------------:|
|  "3V3"   |       "3V3"      |
|  "GND"   |       "GND"      |
|  "SCL"   |        "15"      |
|  "SDA"   |        "16"      |
|  "INT"   |        "27"      |

The USFS can also be "Piggybacked" directly onto the Pesky Products development board using machine pin headers (not shown).

In this configuration the interconnection matrix is:

## USFS "Piggybacked" onto Development Board
| USFS Pin |STM32Dev Board Pin|
|:--------:|:----------------:|
|  "3V3"   |       "13"       |
|  "GND"   |       "12"       |
|  "SCL"   |       "15"       |
|  "SDA"   |       "16"       |
|  "INT"   |       "27"       |
