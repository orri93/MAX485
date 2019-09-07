/*
  MAX485.h - A simple library for using the max485 EIA-485 driver IC from Maxim Integrated.
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
#ifndef MAX485_h
#define MAX485_h

#include "Arduino.h"

enum class Rs485Role {
  Master, Slave
};

class MAX485
{
public:
  MAX485(int pinTE);
  MAX485(int pinRE, int pinDE);
  void initialize(const Rs485Role& role = Rs485Role::Slave);
  void set(const Rs485Role& role);
  boolean is(const Rs485Role& role);
	void sending(boolean setCarrier);
private:
  int _pinRE;
	int _pinDE;
};

#endif