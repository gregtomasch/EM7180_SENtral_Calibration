# Teensy 3.X and Invensense USFS
Interconnection of the USFS to the Teensy 3.x is simple. The information given here is valid for the [Teensy 3.1/3.2](https://www.pjrc.com/store/teensy32.html), [Teensy 3.5](https://www.pjrc.com/store/teensy35.html) and [Teensy 3.6](https://www.pjrc.com/store/teensy36.html) development boards. For testing on a prototyping ["Breadboard"](https://cdn-shop.adafruit.com/1200x900/443-00.jpg) the interconnection matrix is:

## Prototype Breadboard
| USFS Pin |Teensy 3.X Pin|
|:--------:|:------------:|
|  "3V3"   |     "3V3"    |
|  "GND"   |     "GND"    |
|  "SCL"   |    "16/SCL" |
|  "SDA"   |    "17/SDA" |
|  "INT"   |      "8"    |

![alt text](https://user-images.githubusercontent.com/5760946/53302638-35d30000-3815-11e9-93a3-4b7bdc6edbb6.png)
