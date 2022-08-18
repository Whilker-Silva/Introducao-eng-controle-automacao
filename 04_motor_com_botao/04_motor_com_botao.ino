#define botao 11
#define motor 12

void setup()
{
    pinMode(botao, INPUT);
    pinMode(motor, OUTPUT);
}

void loop()
{
    digitalWrite(motor, HIHG);

    if (digitalRead(botao) == 1)
    {
        digitalWrite(motor, LOW);
    }
}