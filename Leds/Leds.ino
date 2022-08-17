int led[] = {12, 11, 10, 9, 8, 7}; // definindo os pinos do led em forma de matriz

void setup()
{
    pinMode(led[0], OUTPUT); // definindo modo do pino dos leds
    pinMode(led[1], OUTPUT); // definindo modo do pino dos leds
    pinMode(led[2], OUTPUT); // definindo modo do pino dos leds
    pinMode(led[3], OUTPUT); // definindo modo do pino dos leds
    pinMode(led[4], OUTPUT); // definindo modo do pino dos leds
    pinMode(led[5], OUTPUT); // definindo modo do pino dos leds
}

void loop()
{

    for (byte x = 0; x < 6; x++)
    {
        // Piscando o led de acorcom a posição x na matriz
        // usado for para realizar a variação de x sem a necessidade de repetir o código
        digitalWrite(led[x], HIGH);
        delay(100);
        digitalWrite(led[x], LOW);
        delay(100);
    }

    for (byte x = 5; x > 0; x--)
    {
        // Piscando o led de acorcom a posição x na matriz
        // usado for para realizar a variação de x sem a necessidade de repetir o código
        digitalWrite(led[x], HIGH);
        delay(100);
        digitalWrite(led[x], LOW);
        delay(100);
    }
}