/*
  Seeed_LED_Bar.cpp
  This is a Suli compatable Library
  
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

#include "Seeed_LED_Bar.h"


IO_T __pinClk;
IO_T __pinDta;

int __led_state = 0;

void led_bar_init(PIN_T pinClk, PIN_T pinDta)
{
    suli_pin_init(&__pinClk, pinClk);
    suli_pin_dir(&__pinClk, HAL_PIN_OUTPUT);
    
    suli_pin_init(&__pinDta, pinDta);
    suli_pin_dir(&__pinDta, HAL_PIN_OUTPUT);
}

void latchData()
{
    suli_pin_write(&__pinDta, LOW);
    suli_delay_us(10);

    for(int i=0; i<4; i++)
    {
        suli_pin_write(&__pinDta, HIGH);
        suli_pin_write(&__pinDta, LOW);
    }
}

void send16bitData(unsigned int data)
{
    for(int i=0; i<16; i++)
    {
        unsigned int state = data&0x8000 ? HIGH : LOW;
        suli_pin_write(&__pinDta, state);

        state = suli_pin_read(&__pinClk) ? LOW : HIGH;
        suli_pin_write(&__pinClk, state);

        data <<= 1;
    }
}

// set led single bit, red to green, one bit for each led
// such as, index_bits = 0x05, then led 1 and led 3 will be on and the others will be off
// 0x0   = 0b000000000000000 = all leds off
// 0x05  = 0b000000000000101 = leds 1 and 3 on, the others off
// 0x155 = 0b000000101010101 = leds 1,3,5,7,9 on, 2,4,6,8,10 off
// 0x3ff = 0b000001111111111 = all leds on
void led_bar_index_bit(unsigned int index_bits)
{
    send16bitData(CMDMODE);

    for (int i=0;i<12;i++)
    {
        unsigned int state = (index_bits&0x0001) ? ON : SHUT;
        send16bitData(state);

        index_bits = index_bits>>1;
    }

    latchData();
}

// set level 0-10, red to green, where 1 is red
// level 0 means all leds off while level 5 means leds 1-5 on and 6-10 will be off
void led_bar_set_level(int level)
{
    if(level>10)return;

    send16bitData(CMDMODE);

    for(int i=0;i<12;i++)
    {
        unsigned int state1 = (i<level) ? ON : SHUT;
        
        send16bitData(state1);
    }

    latchData();
}

// set level 0-10 in reverse, green to red, where 10 is red
// level 0 means all leds off while level 5 means leds 1-5 on and 6-10 will be off
void led_bar_set_level_reverse(int level)
{
    if(level>10)return;

    send16bitData(CMDMODE);

    for(int i=0;i<12;i++)
    {
        unsigned int state1 = (i>=(10-level)) ? ON : SHUT;

        send16bitData(state1);
    }

    latchData();
}

// control a single led
// num - which led
// state - 1: on   0: off
void led_bar_single_led(int num, int state)
{
    if(num>10)return;

    __led_state = state ? (__led_state | (0x01<<num)) : (__led_state & ~(0x01<<num));

    led_bar_index_bit(__led_state);
}

