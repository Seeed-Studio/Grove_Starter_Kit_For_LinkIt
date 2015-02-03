/*
  Copyright (c) 2014 MediaTek Inc.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License..

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.
   
  Note: Only D9 and D10 is supported
*/

#include <Servo.h> 

Servo myservo;

void setup() 
{
    Serial.begin(115200);
    myservo.attach(9);
    myservo.write(90);
}

void loop() 
{

    for(int i=0; i<180; i++)
    {
        myservo.write(i);
        delay(15);
    }
    
    for(int i=179; i>=0; i--)
    {
        myservo.write(i);
        delay(15);
    }
   
}
