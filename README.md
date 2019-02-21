# EM7180 USFS Sensor Calibration Utilities

## Background
Tlera Corporation offers a popular set of attitude and heading reference system (AHRS) boards known as the "Ultimate Sensor Fusion Solution" or USFS. The heart of the USFS is [EMMicroelectronic's EM7180](https://www.emmicroelectronic.com/product/sensor-fusion/em7180-sentral) sensor fusion coprocessor, which uses PNICorp's [“SpacePoint<sup>TM</sup>”](https://www.pnicorp.com/mm-module/) adaptive fusion algorithm. With proper sensor calibration, the USFS can readily provide heading accuracy of [~2deg RMS or better](https://github.com/kriswiner/EM7180_SENtral_sensor_hub/wiki/K.-Limits-of-Absolute-Heading-Accuracy-Using-Inexpensive-MEMS-Sensors). The [original USFS ](https://www.tindie.com/products/onehorse/ultimate-sensor-fusion-solution-mpu9250/) is based upon the EM7180, TDK/Invensense's popular [MPU9250](https://www.invensense.com/products/motion-tracking/9-axis/mpu-9250/) 9DOF accel/gyro/magnetometer chip and Bosch's [BMP280](https://www.bosch-sensortec.com/bst/products/all_products/bmp280) pressure transducer.

![alt text](https://user-images.githubusercontent.com/5760946/53206889-0474ed00-35e7-11e9-8590-22fa937f65da.png)

This version of the USFS board has enjoyed wide acceptance by many different users for numerous applications. However, TDK has announced that the MPU9250 has reached end-of-life and production will soon cease.

Last year Tlera brought out a successor to the original USFS that is based upon the EM7180 and the latest suite of ST Micro MEMS sensors. 

![alt text](https://user-images.githubusercontent.com/5760946/53206940-29696000-35e7-11e9-852d-feb112114ab7.png)

They include the 6DOF [LSM6DSM](https://www.st.com/en/mems-and-sensors/lsm6dsm.html) accel/gyro, the 3DOF [LIS2MDL](https://www.st.com/en/mems-and-sensors/lis2mdl.html) magnetometer and the [LPS22HB](https://www.st.com/en/mems-and-sensors/lps22hb.html) barometric pressure sensor. [Initial characterization](https://github.com/kriswiner/EM7180_SENtral_sensor_hub/wiki/K.-Limits-of-Absolute-Heading-Accuracy-Using-Inexpensive-MEMS-Sensors) of the ST-based USFS board shows that it delivers performance that is every bit as good (if not better) than the Invensense-based USFS.
