/*
 * Copyright (c) 2019 Gregory Tomasch.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimers.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimers in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The names of Gregory Tomasch and his successors
 *     may not be used to endorse or promote products derived from this Software
 *     without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.
 */

#ifndef config_h
#define config_h

/*************************************************************************************************/
/*************                                                                     ***************/
/*************                     SECTION  1 - BASIC SETUP                        ***************/
/*************                                                                     ***************/
/*************************************************************************************************/
    #define SERIAL_DEBUG
    #define SENSOR_0_WIRE_INSTANCE             Wire
    #define I2C_PINS                           I2C_PINS_16_17                                           // USFS
    #define LED_PIN                            13
    #define INT_PIN                            8

    #define UPDATE_PERIOD                      100                                                      // Screen/serial update period (ms)

/********************                   EM7180 IMU Board                   **********************/
    /* Add boards as they become available */
    #define USFS                                                                                        // Pesky Products USFS or other EM7180 + MPU9250 board
    
/**************************            Sensor Data Rates              ****************************/
    /* MPU9250 Acc Output data rate. Uncomment only one option */
    #define ACC_ODR                            0x64   // 1000Hz
    //#define ACC_ODR                            0x32   // 500Hz
    //#define ACC_ODR                            0x14   // 200Hz
    //#define ACC_ODR                            0x0A   // 100Hz

    /* MPU9250 Gyro Output data rate. Uncomment only one option */
    #define GYRO_ODR                           0x64   // 1000Hz
    //#define GYRO_ODR                           0x32   // 500Hz
    //#define GYRO_ODR                           0x14   // 200Hz
    //#define GYRO_ODR                           0x0A   // 100Hz

    /* MPU9250 Gyro Output data rate. Uncomment only one option */
    #define MAG_ODR                            0x64   // 100Hz
    //#define MAG_ODR                            0x32   // 50Hz
    //#define MAG_ODR                            0x14   // 20Hz
    //#define MAG_ODR                            0x0A   // 10Hz

    /* BMP280 Baro Output data rate. Uncomment only one option */
    #define BARO_ODR                           0x19   // 25Hz
    //#define BARO_ODR                           0x32   // 50Hz
    //#define BARO_ODR                           0x53   // 83Hz

    /* EM7180 Quaternion rate divisor; quaternion rate is the gyro ODR (in Hz) divided by the quaternion rate divisor + 1. Uncomment only one option */
    #define QUAT_DIV                           0x09   // 10
    //#define QUAT_DIV                           0x04   // 5
    //#define QUAT_DIV                           0x03   // 4
    //#define QUAT_DIV                           0x01   // 2

/**************************              Sensor Scales                ****************************/
    /* MPU9250 Acc Output Scale. Uncomment only one option */
    //#define ACC_SCALE                          0x02   // +/-2g
    //#define ACC_SCALE                          0x04   // +/-4g
    #define ACC_SCALE                          0x08   // +/-8g
    //#define ACC_SCALE                          0x10   // +/-16g

    /* MPU9250 Gyro Output Scale. Uncomment only one option */
    //#define GYRO_SCALE                         0xFA   // +/-250DPS
    //#define GYRO_SCALE                         0x1F4  // +/-500DPS
    //#define GYRO_SCALE                         0x3E8  // +/-1000DPS
    #define GYRO_SCALE                         0x7D0  // +/-2000DPS

    /* MPU9250 Acc Output Scale. Uncomment only one option */
    #define MAG_SCALE                          0x3E8  // +/-1000uT

/**************************          Gyro/Accel LP Filters            ****************************/
    /* MPU9250 Gyro low pass filter setting. Uncomment only one option */
    //#define MPU9250_GYRO_LPF_184HZ // (Default)
    //#define MPU9250_GYRO_LPF_92HZ
    #define MPU9250_GYRO_LPF_41HZ
    //#define MPU9250_GYRO_LPF_20HZ
    //#define MPU9250_GYRO_LPF_10HZ
    //#define MPU9250_GYRO_LPF_5HZ

    /* MPU9250 Acc low pass filter setting. Uncomment only one option */
    //#define MPU9250_ACC_LPF_460HZ  (Default)
    //#define MPU9250_ACC_LPF_184HZ
    //#define MPU9250_ACC_LPF_92HZ
    #define MPU9250_ACC_LPF_41HZ
    //#define MPU9250_ACC_LPF_20HZ
    //#define MPU9250_ACC_LPF_10HZ
    //#define MPU9250_ACC_LPF_5HZ

/**************************          Sentral Calibrations             ****************************/
      /* These configuration definitions allow the user to select whether or not to use
         the stored accel cal and WS parameters. Defined as "1", the accel/WS data will
         be loaded if valid. Defined as "0", the accel/WS data will NOT be loaded, even
         if it is valid... */

      /* Define as 0 to suppress Acc scale/offset corrections. Uncomment only one option */
      #define ACCEL_CAL                   1
      //#define ACCEL_CAL                   0

      /* Define as 0 to suppress Sentral "Warm Start" heading correction. Uncomment only one option */
      #define SENTRAL_WARM_START          1
      //#define SENTRAL_WARM_START          0

/********************                 Magnetic Declination                 ***********************/

      /* Magnetic decliniation data: http://magnetic-declination.com/
         Units are decimal degrees (Not DMS)*/
         
      //#define MAG_DECLINIATION            13.80f // For Sunnyvale, CA USA.
      //#define MAG_DECLINIATION            14.30f // For Kelseyville, CA USA.
      #define MAG_DECLINIATION            14.05f // Composite between Sunnyvale and Kelseyville

/**************************            End Configuration              ****************************/

#endif
