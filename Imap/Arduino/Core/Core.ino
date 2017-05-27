#include <TimerOne.h>

bool _blink = false;
bool blinkstat = false;
int incomingByte = 0;


// Callback функция по таймеру
void timerIsr()
{
  if(_blink)
  {
    blinking();
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
  Timer1.initialize();  
  Timer1.attachInterrupt( timerIsr ); 
  Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {  //если есть доступные данные
        // считываем байт
        incomingByte = Serial.read()-48;
        if(incomingByte == 50)
        {
          Serial.print("h");
        }
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
          default:
            off();
        }
        /*Serial.print("I received: ");
        Serial.println(incomingByte, DEC);*/
        
    }

}

void off()
{
  _blink = false;
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
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
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
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
}
void p6()
{
  off();
  _blink = true;
}
void blinking()
{
  blinkstat = !blinkstat;
  digitalWrite(6, blinkstat);
  digitalWrite(7, blinkstat);
  digitalWrite(8, blinkstat);
  digitalWrite(9, blinkstat);
  digitalWrite(10, blinkstat);
  digitalWrite(11, blinkstat);
  digitalWrite(12, blinkstat);
  digitalWrite(13, blinkstat);
  
}

