// demo of led bar, set single led
// there are 10 leds you can toggle

#include <Suli.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Seeed_LED_Bar_Arduino.h"

SeeedLedBar bar(A4, A5);                  // CLK, DTA

void setup()
{

}

void loop()
{
    for(int i=1; i<=10; i++)
    {
        if(i == 1)
        {
            // reset
            bar.singleLed(i, 1);          // led 1 on
            bar.singleLed(i+9, 0);        // led 10 off
        }
        else
        {
            // sweep
            bar.singleLed(i, 1);          // led i on
            bar.singleLed(i-1, 0);        // led i-1 off
        }
        
        delay(100);
    }
}
