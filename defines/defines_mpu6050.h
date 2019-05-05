/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2011 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/
/*-------------------------------------------Libraries used for MPU-6050-------------------------------------------*/
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
MPU6050 mpu;
/*--------------------------------------------------------Others---------------------------------------------------*/
#define OUTPUT_READABLE_YAWPITCHROLL

/********************************************************************************************************************/

// MPU control/status vars
bool      dmpReady      = false;      // set true if DMP init was successful
uint8_t   mpuIntStatus;               // holds actual interrupt status byte from MPU
uint8_t   devStatus;                  // return status after each device operation (0 = success, !0 = error)
uint16_t  packetSize;                 // expected DMP packet size (default is 42 bytes)
uint16_t  fifoCount;                  // count of all bytes currently in FIFO
uint8_t   fifoBuffer[64];             // FIFO storage buffer

// orientation/motion vars
Quaternion q;                         // [w, x, y, z]         quaternion container
VectorFloat gravity;                  // [x, y, z]            gravity vector
float ypr[3];                         // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
bool	  isDataReady	= false;	  // Check if data is available
// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;   // indicates whether MPU interrupt pin has gone high
/********************************************************************************************************************/