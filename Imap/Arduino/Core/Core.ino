#include <TimerOne.h>

bool _blink = false;
bool blinkstat = false;

bool _blink_p6 = false;
bool blinkstat_p6 = false;

bool _blink_p8 = false;
bool blinkstat_p8 = false;

bool _blink_p12 = false;
bool blinkstat_p12 = false;

int incomingByte = 0;


// Callback функция по таймеру
void timerIsr()
{
  if(_blink)
  {
    blinking();
  }
  if(_blink_p6)
  {
    blinkig_p6();
  }
  if(_blink_p8)
  {
    blinkig_p8();
  }
  if(_blink_p12)
  {
    blinkig_p12();
  }
}

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  off();
  Timer1.initialize();  
  Timer1.attachInterrupt( timerIsr ); 
  Serial.begin(9600);
}

void loop() {

    if (Serial.available() > 0) {  //если есть доступные данные
        // считываем байт
        incomingByte = Serial.read()-48;
        Serial.print(incomingByte);
        off();
        switch(incomingByte)
        {
          case 1:
            p1();
            break;
          case 2:
            p2();
            break;
          case 3:
            p3();
            break;
          case 4:
            p4();
            break;
          case 5:
            p5();
            break;
          case 6:
            p6();
            break;
          case 7:
            p7();
            break;
          case 8:
            p8();
            break;
          case 9:
            p9();
            break;
          case 10:
            p10();
            break;
          case 11:
            p11();
            break;
          case 12:
            p12();
            break;
          case 13:
            p13();
            break;
          //default:
            //off();
        }
    }
}

void off()
{
  _blink = false;
  _blink_p6 = false;
  _blink_p8 = false;
  _blink_p12 = false;
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
void on()
{
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void p1()
{
  off();
  on();
}
void p2()
{
  off();
  on();
}
void p3()
{
  off();
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
}
void p4()
{
  off();
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}
void p5()
{
  off();
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
}
void p6()
{
  off();
  _blink_p6 = true;
}
void p7()
{
  off();
}
void p8()
{
  off();
  _blink_p8 = true;
}
void p9()
{
  off();
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
}
void p10()
{
  off();
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
}
void p11()
{
  off();
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}
void p12()
{
  off();
  _blink_p12 = true;
}
void p13()
{
  off();
  _blink = true;
}

void blinkig_p8()
{
  blinkstat_p8 = !blinkstat_p8;
  digitalWrite(13, blinkstat_p8);
}
void blinkig_p6()
{
  blinkstat_p6 = !blinkstat_p6;
  digitalWrite(9, blinkstat_p6);
}
void blinkig_p12()
{
  blinkstat_p12 = !blinkstat_p12;
  digitalWrite(8, blinkstat_p12);
  digitalWrite(9, blinkstat_p12);
  digitalWrite(11, blinkstat_p12);
  digitalWrite(12, blinkstat_p12);
}
void blinking()
{
  blinkstat = !blinkstat;
  digitalWrite(6, blinkstat);
  digitalWrite(7, blinkstat);
  digitalWrite(8, blinkstat);
  digitalWrite(11, blinkstat);//11
  
}

