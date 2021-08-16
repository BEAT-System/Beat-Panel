#include <Arduino.h>
#include "VentiData.h"
#include "Beat2020Regler.h"
#include "Beat2020Panel.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

// ####################### D E F I N E    C O N S T A N T S #######################
#define Nvalues 20

// ########################### L C D   V A R I A B L E S ##########################
uint16_t sets[3];
float acts[3];
uint16_t values[Nvalues];
uint16_t valuesR[Nvalues];

// ####################### K E Y P A D   V A R I A B L E S ########################
const byte COLS = 4;            // 4 Columns
const byte ROWS = 3;            // 3 Rows
char hexaKeys[ROWS][COLS] = {     // Definition of certain char for every key
{'Z','-','d','3'},
{'>','O','<','2'},
{'A','+','u','1'}
};
byte colPins[COLS] = { 2,3,4,5 }; //Definition of 4 Column-Pins
byte rowPins[ROWS] = { 6,7,8 };   //Definition of 3 Row-Pins
char Button;                    // stores char of pressed key


// ######################## D E C L A R E   O B J E C T S #########################
LiquidCrystal_I2C display(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); // function for reading pressed key

PanelData pData = EmptyPanelData();
ControllerData cData = EmptyControllerData();
Beat2020Regler regler(cData, pData);
Parameter params1[]{
	  Parameter("Bpm",pData.bpm,"[ ]",1,32),
	  Parameter("P_ins",pData.p_ins,"[ ]",1,32),
	  Parameter("P-exp",pData.p_exp,"[ ]",1,32)
};

Parameter params2[]{
  Parameter("Bpm", pData.bpm, "[ ]", (uint16_t)1, (uint16_t)32),
  Parameter("P_ins",pData.p_ins,"[ ]",1,32),
  Parameter("P-exp",pData.p_exp,"[ ]",1,32)
};

SetUpMenu menu1(display, keypad, params1, 3);
SetUpMenu menu2(display, keypad, params2, 3);
TestMenu menu3(display, keypad);

IMenu* submenus[3]{
  &menu1,
  &menu2,
  &menu3 };

MainMenu menu(display, keypad, submenus, (byte)3);

void setup() {
	// put your setup code here, to run once:
}

void loop() {
	// put your main code here, to run repeatedly:
}