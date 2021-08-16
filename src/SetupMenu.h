#ifndef SetUpMenu_H
#define SetUpMenu_H

#include "IMenu.h"
#include "Parameter.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

class SetUpMenu : public IMenu {
private:
	IMenu* _parent;
	Parameter* _params;
	LiquidCrystal_I2C& _display;
	Keypad& _keypad;
	byte _params_size;
	byte _param_id;
public:
	SetUpMenu(LiquidCrystal_I2C& display, Keypad& keypad, Parameter* params, byte params_size);
	void update();
	void setParent(IMenu* parent);
	~SetUpMenu();
};

SetUpMenu::SetUpMenu(LiquidCrystal_I2C& display, Keypad& keypad, Parameter* params, byte params_size):
	_display(display),
	_keypad(keypad),
	_params_size(params_size),
	_param_id(params_size)
{
	_params = params;
}

void SetUpMenu::update(){

}

void SetUpMenu::setParent(IMenu* parent){ _parent = parent;}

SetUpMenu::~SetUpMenu(){
}

#endif