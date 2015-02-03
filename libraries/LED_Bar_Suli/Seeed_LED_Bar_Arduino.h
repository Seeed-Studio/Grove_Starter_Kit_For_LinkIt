/*
  Seeed_LED_Bar_Arduino.h
  For Arduino Only
  This is a Suli compatible Library
  
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.
  
  Loovee
  2013-3-26

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __SEEED_LED_BAR_ARDUINO_H__
#define __SEEED_LED_BAR_ARDUINO_H__

#include "Seeed_LED_Bar.h"

class SeeedLedBar{

public:

/*
 * Initialize, set pin number
 */
SeeedLedBar(int pinClk, int pinDta)         // CLK, DTA
{
    //led_bar_init((PIN_T)pinClk, (PIN_T)pinDta);
}
    
/*
 * set led single bit, red to green, one bit for each led
 * such as, index_bits = 0x05, then led 1 and led 3 will be on and the others will be off
 * 0x0   = 0b000000000000000 = all leds off
 * 0x05  = 0b000000000000101 = leds 1 and 3 on, the others off
 * 0x155 = 0b000000101010101 = leds 1,3,5,7,9 on, 2,4,6,8,10 off
 * 0x3ff = 0b000001111111111 = all leds on
 */
void indexBit(unsigned int index_bits)
{
    led_bar_index_bit(index_bits);
}

void begin(int pinClk, int pinDta)
{
	led_bar_init((PIN_T)pinClk, (PIN_T)pinDta);
}

/*
 * set level 0-10, red to green, where 1 is red
 * level 0 means all leds off while level 5 means leds 1-5 on and 6-10 will be off
 */
void setLevel(int level)
{
    led_bar_set_level(level);
}

/*
 * set level 0-10 in reverse, green to red, where 10 is red
 * level 0 means all leds off while level 5 means leds 1-5 on and 6-10 will be off
 */
void setLevelReverse(int level)
{
    led_bar_set_level_reverse(level);
}

/*
 * control a single led
 * num - which led
 * state - 1: on   0: off
 */
void singleLed(int num, int state)
{
    led_bar_single_led(num, state);
}


};


#endif
