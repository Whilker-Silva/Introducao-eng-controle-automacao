#define motor 12

void setup()
{
    pinMode(motor, OUTPUT);
}

void loop()
{
    digitalWrite(motor, HIGH);
}