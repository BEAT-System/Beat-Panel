#ifndef MainMenu_H
#define MainMenu_H

#include "IMenu.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>

class MainMenu : public IMenu {
private:
	IMenu** _sub_menues;
	LiquidCrystal_I2C& _display;
	Keypad& _keypad;
	byte _menu_size;
	byte _menu_id;//0.., size->self
public:
	MainMenu(LiquidCrystal_I2C& display, Keypad& keypad, IMenu** menues, byte menu_size);
	void update();
	void setParent(IMenu* parent);
	~MainMenu();
};

MainMenu::MainMenu(LiquidCrystal_I2C& display, Keypad& keypad, IMenu** menues, byte menu_size):
	_display(display),
	_keypad(keypad),
	_menu_size(menu_size),
	_menu_id(_menu_size)
{
	_sub_menues= menues;
	for(int i = 0; i < _menu_size; i++)
	{
		_sub_menues[i]->setParent(this);
	}
}

void MainMenu::update() {
	if (_menu_id < _menu_size)
	{
		_sub_menues[_menu_id]->update();
		return;
	}
	//update this
}

void MainMenu::setParent(IMenu* parent){
	//nothing
}

MainMenu::~MainMenu(){
}

#endif