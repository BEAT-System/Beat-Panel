#ifndef TestMenu_H
#define TestMenu_H

#include "IMenu.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

class TestMenu : public IMenu {
private:
	IMenu* _parent;
	LiquidCrystal_I2C& _display;
	Keypad& _keypad;
public:
	TestMenu(LiquidCrystal_I2C& display, Keypad& keypad);
	void update();
	void setParent(IMenu* parent);
	~TestMenu();
};

TestMenu::TestMenu(LiquidCrystal_I2C& display, Keypad& keypad):
	_display(display),
	_keypad(keypad)
{

}

void TestMenu::update(){
	//du something
}

void TestMenu::setParent(IMenu* parent){
	_parent = parent;
}

TestMenu::~TestMenu(){
}


#endif