/*
  MAX485.cpp - A simple library for using the max485 EIA-485 driver IC from Maxim Integrated.
  Copyright 2016 Stefan Thema (swarkn), http://do-it-neat.com <swarkn@do-it-neat.com>
  
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Arduino.h"
#include "MAX485.h"

MAX485::MAX485(int pinTE) :
  MAX485(pinTE, pinTE) {
}

MAX485::MAX485(int pinRE, int pinDE) :
  _pinRE(pinRE),
	_pinDE(pinDE) {
}

void MAX485::initialize(const Rs485Role& role) {
	pinMode(_pinRE, OUTPUT);
	if(_pinRE != _pinDE) {
	  pinMode(_pinDE, OUTPUT);
	}
	set(role);
	sending(false);
}

void MAX485::set(const Rs485Role& role) {
	switch(role) {
	case Rs485Role::Master:
		digitalWrite(_pinRE, HIGH);
		break;
	case Rs485Role::Slave:
	  digitalWrite(_pinRE, LOW);
		break;
	}
}

boolean MAX485::is(const Rs485Role& role)
{
	switch(role) {
	case Rs485Role::Master:
		return digitalRead(_pinRE) == HIGH;
	case Rs485Role::Slave:
	  return digitalRead(_pinRE) == LOW;
	default:
	  return false;
	}
}

void MAX485::sending(boolean setCarrier)
{
	digitalWrite(_pinDE, setCarrier ? HIGH : LOW);
}