/* ============================================
MIT License

Copyright (c) 2019 NghiaDT

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
=============================================== */

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void glove_initialize() 
{
  /* Initialize serial communication for debugging */
  Serial.begin(9600);
  while (!Serial);
  
  /* Initialize sensors and buttons */
  sensors_initialize();

  /* Initialize mpu6050 */
  mpu6050_initialize();

  /* Initialize NeoPixel */
  pixel_initialize();
}

// ================================================================
// ===  ===
// ================================================================

void glove_main_task() 
{
  // Start the sequence to record value for flex sensors
  initialization_sequence();

  // Get data from sensors and button
  sensors_get_data();

  // Get data from mpu6050
  mpu6050_get_data();  

  if(isDataReady) 
  {
    if(startProgram == 1)
    {
      for(int i=0; i<5; i++) 
      {
        value[i] = map(value[i], min[i], max[i],0,9);
      }
      standDetection(ypr[0] * 180/M_PI, ypr[1] * 180/M_PI, ypr[2] * 180/M_PI);  

      int level = 9 - ((value[0] + value[1] + value[2] + value[3] + value[4]) / 5);

      switch(runningMode)
      {
        case 0:
          Serial.println("Ruuning Mode 0");
          pixel_running_circle();
          break;
        case 1:
          Serial.println("Ruuning Mode 1");
          pixel_running_mode_1(level);
          break;
        case 2:
          Serial.println("Ruuning Mode 2");
          pixel_running_mode_2(stand);
          break;
        default:
          break;  
      }
    }
  }
}

void initialization_sequence() 
{
  if (buttonState == HIGH) 
  {        
    if(startProgram != 1) 
    {
      bValue++;
    } 
    else 
    {
      runningMode++;
      if(runningMode > 2) 
      {
        runningMode = 0;
      }
      delay(2000);
    }
    
  }
  if(startProgram != 1) 
  {
    if (bValue == 1) 
    {
      Serial.println("button press 1");  
      for(int i=0; i<5; i++) 
      {
        min[i] = value[i];
      }
      bValue++;
      delay(1000);
    }
    if (bValue == 3) 
    {
      Serial.println("button press 2"); 
      max[0] = value[0];
      bValue++;
      delay(1000);
    }
    if (bValue == 5) 
    {
      Serial.println("button press 3"); 
      for(int i=1; i<5; i++) 
      {
        max[i] = value[i];
      }
      bValue = 6;
      startProgram = 1;
      delay(1000);
    }
  } 
}

void standDetection(int yaw, int pitch, int roll) 
{
  if((pitch >=340 || pitch <= 20) && (roll >=340 || roll <=20)) 
  {
    stand = 1;
    Serial.println(stand);
  }

  if(pitch >= 170 && pitch <= 230 && roll >= 170 && roll <= 230) 
  {
    stand = 2;
    Serial.println(stand);
  }  

  if(pitch >=260 && pitch <= 300) 
  {
    stand = 3;
    Serial.println(stand);
  }

  if(roll >= 270 && roll <= 300) 
  {
    //Avoid error
    if( pitch <260 || pitch >300) 
    {
      stand = 4;
      Serial.println(stand);
    }
  } 

  if(roll >= 30 && roll <= 100) 
  {
    //Avoid error
    if( pitch <260 || pitch >300)
    {
      stand = 5;
      Serial.println(stand);
    }
  }  
  delay(1000);
}
