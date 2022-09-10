/*
  teclado da esquerda para direita
  6,7,8,9,10,11,12,13

  display

  pin1--- gnd
  pin2--- 5v
  pin3--- gnd com resistor de 2,2k
  pin4--- A0
  pin5--- gnd
  pin6--- A1
  pin7--- xxx
  pin8--- xxx
  pin9--- xxx
  pin10--- xxx
  pin11--- 2
  pin12--- 3
  pin13--- 4
  pin14--- 5
  pin15--- 5v com resistor de 200
  pin16--- gnd


*/

#include <Keypad.h>
#include <LiquidCrystal.h>
//______________________________________________________________

byte pinL[] = {14, 15, 16, 17};
byte pinC[] = {18, 19, 20, 21};

char teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'.', '0', '#', 'D'}};

Keypad teclado = Keypad(makeKeymap(teclas), pinL, pinC, 4, 4);
//______________________________________________________________

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
//______________________________________________________________

bool estado = false;

float i = 0;
float n = 0;
float pv = 0;

String numero = "";

//______________________________________________________________

void setup()
{

    lcd.begin(16, 2);
    lcd.clear();
    Serial.begin(9600);
    delay(100);
}

void loop()
{

    char push = teclado.getKey();

    if (push)
    {
        if (push != 'A' && push != 'B' && push != 'C' &&
            push != 'D' && push != '#')
        {
            switch (push)
            {

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':

                numero += push;

                lcd.print(push);
                Serial.print(push);
            }
        }

        else if (push == 'A')
        {

            lcd.clear();
            Serial.println();
            i = numero.toFloat();
            numero = "";
            delay(100);
        }

        else if (push == 'B')
        {

            lcd.clear();
            Serial.println();
            n = numero.toFloat();
            numero = "";
            delay(100);
        }

        else if (push == 'C')
        {

            lcd.clear();
            Serial.println();
            pv = numero.toFloat();
            numero = "";
            delay(100);
        }

        else if (push == 'D')
        {

            i = i / 100;

            float cf = i / (1 - (1 / (pow(((1 + i)), n))));
            float pmt = pv * cf;
            float fv = pmt * n;

            lcd.setCursor(0, 0);
            lcd.print("parcela: ");
            lcd.print(pmt);
            Serial.print(pmt);
            Serial.print(" || ");

            lcd.setCursor(0, 1);
            lcd.print("total: ");
            lcd.print(fv);
            Serial.print(fv);
        }

        else if (push == '#')
        {

            lcd.clear();
            Serial.println();
            Serial.println();
            i = 0;
            n = 0;
            pv = 0;
            numero = "";
        }
    }
}
