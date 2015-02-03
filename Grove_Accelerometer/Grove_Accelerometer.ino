/*
 * acc_adxl345 demo code
 *
 * Note:
 * - this is a Suli-compatible Library
 * - You should download Suli for Arduino first
 * - More details, please refer to http://www.seeedstudio.com/wiki/Suli
 */
 
#include <Suli.h>
#include <Wire.h>
#include "acc_adxl345_Arduino.h"


Acc_Adxl345 acc;


void setup()
{
    Serial.begin(9600);
    
    acc.begin();
    
    Serial.println("hello world");
}

void loop()
{
    float ax, ay, az;
    
    acc.get(&ax, &ay, &az);             // get value from adxl345
    
    Serial.print(ax);                   // print it out
    Serial.print('\t');
    Serial.print(ay);
    Serial.print('\t');
    Serial.println(az);
    
    delay(100);                         // delay
}
