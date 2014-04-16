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
//Project Name:	Arduino Template Project Example


#include <EEPROM.h>

//----- GENERAL -----
#include "global.h"          //Global definitions for the project
#define MAIN_C               //Define for my header file
#include "ap__main.h"        //Header file for this main project file

//Header file used by this file:
#include "ap_gen.h"






//***************************
//***************************
//********** SETUP **********
//***************************
//***************************
void setup()
{                

  //------------------------------
  //----- SETUP THE IO PORTS -----
  //------------------------------
  pinMode(ARDUINO_LED, OUTPUT);

  
  //pinMode(2, INPUT_PULLUP);          //Input with pullup resistor


  //----- SETUP RS232 PORT -----
  //Serial2.begin(9600, SERIAL_8N1);

  //----- LOAD NON VOLATILE MEMORY -----
  read_non_volatile();


}


//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

//***********************************
//***********************************
//********** MAIN FUNCTION **********
//***********************************
//***********************************
void loop()
{
  HeartbeatTimer();
  
  switches_1_new = 0;
  if (do_10ms_functions)
  {
    //-----------------------------
    //----- DO 10mS FUNCTIONS -----
    //-----------------------------
    do_10ms_functions = 0;
    
    //----- READ SWICHES -----
    read_switches();
    
  }
  

  //----- CHECK FOR STORE NON VOLATILE MEMORY -----
  //To trigger:
  //  write_non_volatile_100ms_timer = WRITE_NON_VOLATILE_100MS_TIME;
  if (write_non_volatile_100ms_timer == 1)
  {
    write_non_volatile_100ms_timer = 0;
    write_non_volatile();
  }
  
  
  //FLASH OUR LED:
  //digitalWrite(ARDUINO_LED, HIGH);
  //delay(100);
  //digitalWrite(ARDUINO_LED, LOW);
  //delay(100);
}






//*******************************
//*******************************
//********** HEARTBEAT **********
//*******************************
//*******************************
void HeartbeatTimer()
{
  static byte heartbeat_10ms_timer = 0;
  static byte heartbeat_100ms_timer = 0;
  static int heartbeat_1sec_timer = 0;
  static unsigned long heartbeat_last_1ms_time = 0;

  while((micros() - heartbeat_last_1ms_time) >= 1000)      //micros() provides exact 1mS timing, millis() does not!
  {
    heartbeat_last_1ms_time += 1000;
    //-------------------------------
    //----- HEARTBEAT EVERY 1mS -----
    //-------------------------------
  
  
    //-- Toggle pin 13 test heartbeat --
    //static byte toggle = 0;
    //toggle ^= 1;
    //digitalWrite(13, toggle);
  
  
  
  
    heartbeat_10ms_timer++;
    if (heartbeat_10ms_timer >= 10)
    {
      //-------------------------------
      //----- 10mS HEARTBEARTBEAT -----
      //-------------------------------
      heartbeat_10ms_timer = 0;
      
      do_10ms_functions = 1;
            
      
      
    } //if (heartbeat_10ms_timer > 10)
  
    heartbeat_100ms_timer++;
    if (heartbeat_100ms_timer >= 100)
    {
      //--------------------------------
      //----- 100mS HEARTBEARTBEAT -----
      //--------------------------------
      heartbeat_100ms_timer = 0;
      
      if (write_non_volatile_100ms_timer > 1)
        write_non_volatile_100ms_timer--;

      
      
      
    } //if (heartbeat_100ms_timer > 100)
    
    heartbeat_1sec_timer++;
    if (heartbeat_1sec_timer >= 1000)
    {
      //-----------------------------------
      //----- 1 SECOND HEARTBEARTBEAT -----
      //-----------------------------------
      heartbeat_1sec_timer = 0;
      

      
      
      
    } //if (heartbeat_100ms_timer > 100)
  }
}





