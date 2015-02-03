// demo of Grove - Touch Sensor

const int pinTouch = 2;
const int pinLed   = 13;


void setup()
{
    Serial.begin(9600);
    pinMode(pinTouch, INPUT);
    pinMode(pinLed, OUTPUT);
}


void loop()
{
    int state = digitalRead(pinTouch);
    Serial.println(state);
    digitalWrite(pinLed, state);
    
    delay(100);
}