#ifndef __DHT_H__
#define __DHT_H__

#include "Arduino.h"

// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

#define DHT22 22

class DHT 
{
private:
    uint8_t data[6];
    uint8_t _pin, _type, _count;
    boolean read(void);
    unsigned long _lastreadtime;
    boolean firstreading;

public:
    DHT(uint8_t pin, uint8_t type, uint8_t count=6);
    void begin(void);

    int readHT(float *temp, float *humi);
};

#endif
