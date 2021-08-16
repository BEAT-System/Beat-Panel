#ifndef Parameter_H
#define Parameter_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>
class Parameter {
public:
	String _name;
	uint16_t& _value;
	String _unit; 
	uint16_t _max, _min;

	Parameter(const String& name, uint16_t& value, const String& unit, uint16_t max, uint16_t min);
	void print(LiquidCrystal_I2C& lcd, byte line);
	void increaseValue();
	void decreaseValue();
};

Parameter::Parameter(const String& name, uint16_t& value, const String& unit, uint16_t max, uint16_t min):
	_name(name),
	_value(value),
	_unit(unit),
	_max(max),
	_min(min)
{

}

#endif