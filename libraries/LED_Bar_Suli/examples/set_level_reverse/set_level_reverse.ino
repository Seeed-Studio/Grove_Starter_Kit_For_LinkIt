// demo of led bar, set level in reverse, green to red

#include <Suli.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Seeed_LED_Bar_Arduino.h"

SeeedLedBar bar(A4, A5);                  // CLK, DTA

int level = 0;
void setup()
{

}

void loop()
{
    bar.setLevelReverse(level++);

    level = level>10 ? 0 : level;

    delay(100);
}
