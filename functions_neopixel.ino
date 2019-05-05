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
void pixel_initialize() 
{
  pixels.begin(); // This initializes the NeoPixel library.
}

void pixel_running_circle()
{
  for(int i=0; i<NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(10,10,10));

    pixels.show();                                                  // This sends the updated pixel color to the hardware.

    delay(20);                                                // Delay for a period of time (in milliseconds).
  }

//  for(int i=0; i<NUMPIXELS; i++)
//  {
//    pixels.setPixelColor(i, pixels.Color(0,0,0));
//
//    pixels.show();                                                  // This sends the updated pixel color to the hardware.
//
//    delay(delayval);                                                // Delay for a period of time (in milliseconds).
//  }
}

void pixel_running_mode_1(int level) 
{
  for(int i=0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(level, level, level));
      
    pixels.show();                                                 
  }
}

void pixel_running_mode_2(int color) 
{
  for(int i=0; i < NUMPIXELS; i++)
  {
  switch(color)
  {
    case 1:
      pixels.setPixelColor(i, pixels.Color(10, 10, 10));
      break;
    case 2:
      pixels.setPixelColor(i, pixels.Color(0, 0, 10));
      break;
    case 3:
      pixels.setPixelColor(i, pixels.Color(0, 10, 0));
      break;
    case 4:
      pixels.setPixelColor(i, pixels.Color(10, 0, 0));
      break;
    default:
      break;  
  }
  }
  pixels.show();
}
