#include <Servo.h>

#define pinservo 8

Servo servo1;

byte contador = 0;

void setup()
{
    delay(500);
}

void loop()
{

    if (contador < 5)
    {

        for (byte x = 0; x < 90; x++)
        {
            servo1.attach(pinservo);
            servo1.write(x);
            delay(10);
        }

        for (byte x = 90; x > 0; x--)
        {
            servo1.write(x);
            delay(10);
        }

        contador++;
    }
}