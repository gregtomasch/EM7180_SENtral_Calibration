# STM32L4 and Invensense USFS
Interconnection of The USFS to the STM32L4 is simple. The information given here is valid for both the ["Dragonfly"](https://www.tindie.com/products/TleraCorp/dragonfly-stm32l47696-development-board/) and ["Butterfly"](https://www.tindie.com/products/TleraCorp/butterfly-stm32l433-development-board/) STM32L4 development boards. For testing on a prototyping ["Breadboard"](https://cdn-shop.adafruit.com/1200x900/443-00.jpg) the interconnection matrix is:

## Prototype Breadboard
| USFS Pin |Dragonfly/Butterfly Pin|
|:--------:|:---------------------:|
|  "3V3"   |         "3V3"         |
|  "GND"   |         "GND"         |
|  "SCL"   |        "D21/SCL"      |
|  "SDA"   |        "D20/SDA"      |
|  "INT"   |           "D8"        |

The USFS can also be "Piggybacked" directly onto the Dragonfly or Butterfly development board using machine pin headers:

![alt text](https://user-images.githubusercontent.com/5760946/53302755-a890ab00-3816-11e9-9884-c8b349cd6b34.png)

In this configuration the interconnection matrix is:

## USFS "Piggybacked" onto Development Board
| USFS Pin |Dragonfly/Butterfly Pin|
|:--------:|:---------------------:|
|  "3V3"   |         "D31"         |
|  "GND"   |         "D13"         |
|  "SCL"   |        "D21/SCL"      |
|  "SDA"   |        "D20/SDA"      |
|  "INT"   |           "D8"        |
