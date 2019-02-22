# EM7180 USFS Sensor Calibration Utilities

## Introduction
Tlera Corporation offers a popular set of attitude and heading reference system (AHRS) boards known as the "Ultimate Sensor Fusion Solution" or USFS. The heart of the USFS is [EMMicroelectronic's EM7180](https://www.emmicroelectronic.com/product/sensor-fusion/em7180-sentral) sensor fusion coprocessor, which uses PNICorp's [“SpacePoint<sup>TM</sup>”](https://www.pnicorp.com/mm-module/) adaptive fusion algorithm. With proper sensor calibration, the USFS can readily provide heading accuracy of [~2deg RMS or better](https://github.com/kriswiner/EM7180_SENtral_sensor_hub/wiki/K.-Limits-of-Absolute-Heading-Accuracy-Using-Inexpensive-MEMS-Sensors). The [original USFS ](https://www.tindie.com/products/onehorse/ultimate-sensor-fusion-solution-mpu9250/) is based upon the EM7180, TDK/Invensense's popular [MPU9250](https://www.invensense.com/products/motion-tracking/9-axis/mpu-9250/) 9DOF accel/gyro/magnetometer chip and Bosch's [BMP280](https://www.bosch-sensortec.com/bst/products/all_products/bmp280) pressure transducer.

![alt text](https://user-images.githubusercontent.com/5760946/53206889-0474ed00-35e7-11e9-8590-22fa937f65da.png)

This version of the USFS board has enjoyed wide acceptance by many different users for numerous applications. However, TDK has announced that the MPU9250 has reached end-of-life and production will soon cease.

Last year Tlera brought out a successor to the original USFS that is based upon the EM7180 and the latest suite of ST Micro low-power MEMS sensors. 

![alt text](https://user-images.githubusercontent.com/5760946/53206940-29696000-35e7-11e9-852d-feb112114ab7.png)

They include the 6DOF [LSM6DSM](https://www.st.com/en/mems-and-sensors/lsm6dsm.html) accel/gyro, the 3DOF [LIS2MDL](https://www.st.com/en/mems-and-sensors/lis2mdl.html) magnetometer and the [LPS22HB](https://www.st.com/en/mems-and-sensors/lps22hb.html) barometric pressure sensor. [Initial characterization](https://github.com/kriswiner/EM7180_SENtral_sensor_hub/wiki/K.-Limits-of-Absolute-Heading-Accuracy-Using-Inexpensive-MEMS-Sensors) of the ST-based USFS board shows that it delivers performance that is every bit as good (if not better) than the Invensense-based USFS. The ST-based USFS is fully pin-for-pin compatible and behaves essentially the same as the original USFS. The only differences are in the exact register writes to the EM7180 to set up output data rates (ODR's) and low-pass filter (LPF) cutoff frequencies. This is because the available accel/gyro ODR's and LPF settings do not exactly match the MPU9250 as well as the ST magnetometer and baro sensors both have LPF capabilities that are not supported on the MPU9250 and BMP280. All of these settings must be addressed correctly for the ST USFS to operate properly... But if they are, the performance of the ST-based version is excellent.

## Sentral Sensor Calibration Basics
No matter which version of the USFS is chosen, the EM7180 must be configured properly and the MEMS sensors must be calibrated correctly to obtain optimal performance. This can be radily done so that robust AHRS results are obtained but it requires proper attention to detail in both host MCU coding and sensor calibration procedures.

### Accelerometers
Accuracy of the Sentral's pitch and roll estimates ultimately depend upon correcting the offsets and scaling errors of the X, Y and Z accelerometers. The Sentral's adaptive algorithm assumes that the three-axis accelerometer data is correct on its face and DOES NOT address any underlying accelerometer sensor errors. However, at startup the EM7180 is capable of reading accelerometer error correction data from a set of input registers and applies these corrections throughout runtime. The offset and scale corrections for each accelerometer are calculated from readings collected when it is aligned first parallel and then anti-parallel to gravity. As a practical matter, the USFS is aligned and held in six seperate calibration orientations (X, Y, and Z aligned parallel and anti-parallel to gravity) and data is collected, averaged and stored in the on-board I2C EEPROM. These six readings are fetched from the EEPROM at startup and are loaded into the Sentral's accelerometer correction registers.

### Magnetometers
Magnetometer calibration dominates heading estimation performance. Unlike the accelerometers, the magnetometers are calibrated by the Sentral's "SpacePoint" adaptive heading algorithm.  It corrects for the ["Hard iron" and "Soft iron"](https://www.vectornav.com/support/library/magnetometer) non-idealities of the X, Y, and Z magnetometer sensors as well as effects from stray ferromagnetic materials and steady fields in the USFS's immediate environment. However, for Spacepoint algorithm to adapt the USFS board needs to be slowly rotated throughout 3-space, ideally sampling all 3-D board oreintations. You can tell when the SpacePoint algorithm has reached an adequate solution by monitoring the "Algorithm Status" byte of the EM7180. When Algorithm Satus = 8 and the indicated heading is steady, the Sentral has reached "Stable calibration".

It would be rather impractical to "teach" the SpacePoint algorithm (by rotating the USFS randomly throughout all of 3-space) every time the USFS is powered up in order to get good magnetometer calibration. Fortunately, the EM7180 has a "Warm Start" feature that eliminates the need for such tedium. The EM7180 can be paused to transfer the effective parametic "state" of the SpacePoint algorithm to the on-board I2C EEPROM at any time. The same algorithm state parameters can be retreived from the I2C EEPROM and loaded into the EM7180 at startup... So once the algorithm has "learned" and properly calibrated the magnetometers, that information can be stored and then restored every time the EM7180 is initialized.

### Gyroscopes
Gyroscope calibration is by far the simplest as it requires no effort on the part of the user. The Sentral does not attempt to correct for gyroscope scale errors but it does automatically correct zero-motion biases. The algorithm assesses when the USFS is not moving and uses the "At rest" data to predict and correct the individual gyroscope bias estimates Examination of the angular velocities reported while the USFS is at rest shows the bias auto-correction method works very well.

## Software Overview
The code in this repository consists of Arduino C++ sketches for two popular types of general purpose microcontrollers:
* Tlera ["Dragonfly"](https://www.tindie.com/products/TleraCorp/dragonfly-stm32l47696-development-board/) and ["Butterfly"](https://www.tindie.com/products/TleraCorp/butterfly-stm32l433-development-board/) development boards
* [Teensy 3.X](https://www.pjrc.com/teensy/) family of development boards

There are both Invensense and ST specific USFS calibration utilities for each type of microcontroller.
