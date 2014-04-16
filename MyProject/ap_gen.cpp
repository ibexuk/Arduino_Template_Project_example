/*
Provided by IBEX UK LTD http://www.ibexuk.com
Electronic Product Design Specialists
RELEASED SOFTWARE

The MIT License (MIT)

Copyright (c) 2013, IBEX UK Ltd, http://ibexuk.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
//Visit http://www.arduino-developer.com/arduino/ide/arduino-ide/arduino-for-c-programmers for more information
//
//Project Name: Arduino Template Project Example



#include <EEPROM.h>


#include "global.h"         //Global definitions
#define GEN_C               //Define for my header file
#include "ap_gen.h"         //My header file

//Header file used by this file:
#include "ap__main.h"





//***********************************
//***********************************
//********** READ SWITCHES **********
//***********************************
//***********************************
void read_switches (void)
{
  BYTE switches_1_read;
  static BYTE switches_1_last = 0;
  static BYTE switches_1_debounced_last = 0;

  //RESET THE NEW SWITCH PRESS REGISTER
  switches_1_new = 0;
  
  //GET THE SWITCH INPUTS
  switches_1_read = 0;
  //if (!digitalRead(5))
  //  switches_1_read |= 0x01;
  //if (!digitalRead(4))
  //  switches_1_read |= 0x02;
  //if (!digitalRead(3))
  //  switches_1_read |= 0x04;
  
  //DEBOUNCE
  switches_1_debounced = switches_1_last & switches_1_read;
  
  //FLAG NEW BUTTON PRESSES
  switches_1_new = switches_1_debounced ^ switches_1_debounced_last;
  switches_1_new &= switches_1_debounced;
  
  //STORE LAST REGISTERS FOR NEXT TIME
  switches_1_debounced_last = switches_1_debounced;
  switches_1_last = switches_1_read;
}





//***************************************
//***************************************
//********** READ NON VOLATILE **********
//***************************************
//***************************************
#define EEPROM_FACTORY_START_SIGNATURE    0x55

void read_non_volatile (void)
{
  BYTE value;
  BYTE address;
  
  value = EEPROM.read(0);
  if (value != EEPROM_FACTORY_START_SIGNATURE)
  {
    //------------------------------------------------
    //----- FACTORY START - STORE DEFAULT VALUES -----
    //------------------------------------------------
    
    //>>>>>>>>>>
    address = 1;
    //EEPROM.write(address++, 0x00);
    //EEPROM.write(address++, 0x00);
    //<<<<<<<<<<
    
    //Store the factory start done signature
    EEPROM.write(0, EEPROM_FACTORY_START_SIGNATURE);
  }
  
  //>>>>>>>>>>
  address = 1;
  // = EEPROM.read(address++);
  // = EEPROM.read(address++);
  //<<<<<<<<<<
}


//****************************************
//****************************************
//********** STORE NON VOLATILE **********
//****************************************
//****************************************
void write_non_volatile (void)
{
  BYTE value;
  BYTE address;
  
  //>>>>>>>>>>
  address = 1;
  //EEPROM.write(address++, );
  //EEPROM.write(address++, );
  //<<<<<<<<<<
}






