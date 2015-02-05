/* DHT library

MIT license
written by Adafruit Industries
*/

#include "DHT.h"

DHT::DHT(uint8_t pin, uint8_t type, uint8_t count) {
    _pin = pin;
    _type = type;
    _count = count;
    firstreading = true;
}

void DHT::begin(void) {
    // set up the pins!
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH);
    _lastreadtime = 0;
}


int readPin(int pin)
{
    return digitalRead(pin);
}


int DHT::readHT(float *temp, float *humi)
{
    uint8_t laststate = HIGH;
    unsigned long counter = 0;
    uint8_t j = 0, i;
    unsigned long currenttime;

    // pull the pin high and wait 250 milliseconds
    digitalWrite(_pin, HIGH);
    delay(250);

    currenttime = millis();
    if (currenttime < _lastreadtime) {
        // ie there was a rollover
        _lastreadtime = 0;
    }

    if (!firstreading && ((currenttime - _lastreadtime) < 2000)) {
        return true; // return last correct measurement
    }

    firstreading = false;

    _lastreadtime = millis();

    data[0] = data[1] = data[2] = data[3] = data[4] = 0;

    // now pull it low for ~20 milliseconds
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delay(20);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(40);
    pinMode(_pin, INPUT);

    unsigned char count_buf[MAXTIMINGS];
    int count_len = 0;
    // read in timings
    for ( i=0; i < MAXTIMINGS; i++)
    {
        counter = 0;
        while (1)
        {
            if(readPin(_pin) != laststate)
            {
                //if(counter > 9)
                break;
            }
            counter++;
            // delayMicroseconds(1);
            if (counter == 100) 
            {
                break;
            }
        }

        count_buf[count_len++] = counter;
        laststate = readPin(_pin);

        if (counter == 100) break;

        if ((i >= 4) && (i%2 == 0))
        {
            // shove each bit into the storage bytes
            data[j/8] <<= 1;
            if (counter > 25)
            data[j/8] |= 1;
            
            j++;
        }
    }

        float f = 0.0;
        
        f = data[2] & 0x7F;
        f *= 256;
        f += data[3];
        f /= 10;
        if (data[2] & 0x80)
        f *= -1;
    
        if(f>15.0 && f<40.0)
        {
            *temp = f;
            
            
            f = data[0];
            f *= 256.0;
            f += data[1];
            f /= 10.0;
            
            *humi = f;
            
            return true;
        }

    return false;

}
