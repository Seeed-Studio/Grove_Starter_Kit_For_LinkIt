// demo of led bar, set level, red to green

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
    bar.setLevel(level++);

    level = level>10 ? 0 : level;

    delay(100);
}
