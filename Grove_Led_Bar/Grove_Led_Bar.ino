// demo of led bar, set level
// when use Grove - LED Bar with LinkIt ONE
// The switch of Grove - Base Shield should put to 3.3V

#include <Suli.h>
#include <Wire.h>
#include "Seeed_LED_Bar_Arduino.h"

SeeedLedBar bar(3, 2);                  // CLK, DTA

int level = 0;


void setup()
{
    bar.begin(3, 2);
}

void loop()
{
    bar.setLevel(level++);
    
    level = level>10 ? 0 : level;
    
    delay(100);
}