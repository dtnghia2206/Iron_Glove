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
===============================================
*/
/*-------------------------------------------Analog Pins For Flex Sensors------------------------------------------*/
#define finger1 A6  //Thumb
#define finger2 A0  //ForeFinger
#define finger3 A1  //MiddleFinger
#define finger4 A2  //RingFinger
#define finger5 A3  //SmallFinger
/*--------------------------------------------------Button Pins----------------------------------------------------*/
const int buttonPin     = 3;         // the number of the pushbutton pin
int       buttonState   = 0;         // variable for reading the pushbutton status
/*---------------------------------------------5 Variables For 5 Fingers-------------------------------------------*/
int       value[5];
int       min[5]; 
int       max[5]; 
/*----------------------------------------------------Others Defines-----------------------------------------------*/
int       bValue=0;
int       startProgram  = 0;
int  	  stand;
int		  runningMode	= 0;
/********************************************************************************************************************/
