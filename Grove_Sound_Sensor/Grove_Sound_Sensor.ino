// demo of Grove - Sound Sensor

const int pinSound = A0;


void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int value = analogRead(pinSound);
    Serial.println(value);
    delay(100);
}