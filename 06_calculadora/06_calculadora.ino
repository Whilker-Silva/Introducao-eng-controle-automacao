
// definindo pinos dos bostões
#define botao1 2
#define botao2 3

// Definindo pino dos leds
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

// criando variáveis para controle da lógica
byte estado = 0;
byte contador1 = 0;
byte contador2 = 0;
byte numero1 = 0;

void setup()
{
    // definindo pinos dos leds como saída
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

    // definindo pinos dos botões como entrada
    pinMode(botao1, INPUT);
    pinMode(botao2, INPUT);

    // desligando todos os leds para inicio correto do contador
    ligaled5(0);
}

void loop()
{
    // primeira contagem
    while (estado == 0)
    {
        /*se o botão 1 for pressionado, incrementar na variável de contagem
        e acender leds de acordo com o valor da variável*/
        if (digitalRead(botao1) == 1)
        {
            contador1++;
            if (contador1 > 5)
            {
                contador1 = 0;
            }

            delay(500);
            ligaled5(contador1);
        }

        /*se o botão 2 for pressionado, apagar os leds e
        começão estado 1 ou seja iniciar segunda contagem*/
        if (digitalRead(botao2) == 1)
        {

            delay(500);
            ligaled5(0);
            estado = 1;
        }
    }

    // primeira contagem
    while (estado == 1)
    {
        /*se o botão 1 for pressionado, incrementar na variável de contagem
        e acender leds de acordo com o valor da variável*/
        if (digitalRead(botao1) == 1)
        {
            contador2++;
            if (contador2 > 5)
            {
                contador2 = 0;
            }

            delay(500);
            ligaled5(contador2);
        }

        /*se o botão 2 for pressionado, apagar os leds e
        começão estado 2 ou seja mostrar o resultado*/
        if (digitalRead(botao2) == 1)
        {
            delay(500);
            ligaled5(0);
            estado = 2;
        }
    }

    //mostrar resultado
    while (estado == 2)
    {
        numero1 = contador1 + contador2;
        ligaled5(numero1);

        /*se o botão 2 for pressionado, apagar os leds e
        começão estado 0 ou seja recomeçar a lógica*/
        if (digitalRead(botao2) == 1)
        {
            delay(500);
            ligaled5(0);
            estado = 0;
            contador1 = 0;
            contador2 = 0;
            numero1 = 0;
        }
    }
}

//Função para ligar os leds de acordo com a contagem;
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

    if (x == 6)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
    }

    if (x == 7)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
    }

    if (x == 8)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
    }

    if (x == 9)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
        digitalWrite(led9, HIGH);
    }

    if (x == 10)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        digitalWrite(led8, HIGH);
        digitalWrite(led9, HIGH);
        digitalWrite(led10, HIGH);
    }
}