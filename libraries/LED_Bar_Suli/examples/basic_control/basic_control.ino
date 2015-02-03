// demo of led bar, set index bit

// control all 10 leds with bits
// each bit from the right controls leds 1-10
// the last 5 bits are ignored

// 0x0   = 0b000000000000000 = all leds off
// 0x05  = 0b000000000000101 = leds 1 and 3 on, the others off
// 0x155 = 0b000000101010101 = leds 1,3,5,7,9 on, 2,4,6,8,10 off
// 0x3ff = 0b000001111111111 = all leds on

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
    // all on
    bar.indexBit(0b000001111111111);

    delay(100);

    // odd leds on, 1,3,5,7,9
    bar.indexBit(0b000000101010101);

    delay(100);

    // even leds on, 2,4,6,8,10
    bar.indexBit(0b000001010101010);

    delay(100);

    // first half on, 1,2,3,4,5
    bar.indexBit(0b000000000011111);

    delay(100);

    // second half on 6,7,8,9,10
    bar.indexBit(0b000001111100000);

    delay(100);
}
