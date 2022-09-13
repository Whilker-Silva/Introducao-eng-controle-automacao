#define botao1 2
#define botao2 3
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8
#define led6 9
#define led7 10
#define led8 11
#define led9 12
#define led10 13

byte estado = 0;
// byte estado2 = 0;
byte contador1 = 0;
byte contador2 = 0;
byte numero1 = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
    pinMode(led8, OUTPUT);
    pinMode(led9, OUTPUT);
    pinMode(led10, OUTPUT);
    pinMode(botao1, INPUT);
    pinMode(botao2, INPUT);
}

void loop()
{
    while (estado == 0)
    {
        if (digitalRead(botao1) == 1)
        {
            while (digitalRead(botao1) == 1)
            {
                Serial.print("aguardando");
            }
            contador1++;
            Serial.println("aguardando");
            Serial.print(contador1);
            ligaled5(contador1);
        }

        if (digitalRead(botao2 == 1))
        {
            while (digitalRead(botao2) == 1)
            {
            }
            estado = 1;
            ligaled5(0);
        }
    }

    while (estado == 1)
    {
        if (digitalRead(botao1) == 1)
        {
            while (digitalRead(botao1) == 1)
            {
            }
            contador2++;
            ligaled5(contador2);
        }

        if (digitalRead(botao2 == 1))
        {
            while (digitalRead(botao2) == 1)
            {
            }
            estado = 2;
            ligaled5(0);
        }
    }

    if (estado == 2)
    {
        numero1 = contador1 + contador2;
    }
}

void ligaled5(byte x)
{

    if (x == 0)
    {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
        digitalWrite(led9, LOW);
        digitalWrite(led10, LOW);
    }

    if (x == 1)
    {
        digitalWrite(led1, HIGH);
    }

    if (x == 2)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
    }

    if (x == 3)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
    }

    if (x == 4)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    }

    if (x == 5)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
    }
}