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


//*****************************
//*****************************
//********** DEFINES **********
//*****************************
//*****************************
#ifndef GEN_C_INIT		//Do only once the first time this file is used
#define	GEN_C_INIT




//--------------------------
//----- SWITCH DEFINES -----
//--------------------------
//#define SWITCH_MENU_PRESSED		((switches_1_debounced & 0x01) ? 1 : 0)
//#define SWITCH_EXIT_PRESSED		((switches_1_debounced & 0x02) ? 1 : 0)
//#define SWITCH_UP_PRESSED		((switches_1_debounced & 0x04) ? 1 : 0)
//#define SWITCH_DOWN_PRESSED		((switches_1_debounced & 0x08) ? 1 : 0)

//#define SWITCH_MENU_NEW_PRESS		((switches_1_new & 0x01) ? 1 : 0)
//#define SWITCH_EXIT_NEW_PRESS		((switches_1_new & 0x02) ? 1 : 0)
//#define SWITCH_UP_NEW_PRESS		((switches_1_new & 0x04) ? 1 : 0)
//#define SWITCH_DOWN_NEW_PRESS	        ((switches_1_new & 0x08) ? 1 : 0)


#endif




//*******************************
//*******************************
//********** FUNCTIONS **********
//*******************************
//*******************************
#ifdef GEN_C
//-----------------------------------
//----- INTERNAL ONLY FUNCTIONS -----
//-----------------------------------


//-----------------------------------------
//----- INTERNAL & EXTERNAL FUNCTIONS -----
//-----------------------------------------
//(Also defined below as extern)
void read_switches (void);
void read_non_volatile (void);
void write_non_volatile (void);


#else
//------------------------------
//----- EXTERNAL FUNCTIONS -----
//------------------------------
extern void read_switches (void);
extern void read_non_volatile (void);
extern void write_non_volatile (void);


#endif




//****************************
//****************************
//********** MEMORY **********
//****************************
//****************************
#ifdef GEN_C
//--------------------------------------------
//----- INTERNAL ONLY MEMORY DEFINITIONS -----
//--------------------------------------------



//--------------------------------------------------
//----- INTERNAL & EXTERNAL MEMORY DEFINITIONS -----
//--------------------------------------------------
//(Also defined below as extern)
BYTE switches_1_debounced = 0;
BYTE switches_1_new = 0;


#else
//---------------------------------------
//----- EXTERNAL MEMORY DEFINITIONS -----
//---------------------------------------
extern BYTE switches_1_debounced;
extern BYTE switches_1_new;


#endif








