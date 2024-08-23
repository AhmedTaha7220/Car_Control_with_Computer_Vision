#include <SoftwareSerial.h>
int rx = 8;
int tx = 9;
SoftwareSerial blu(rx, tx);

#define r_pos 5
#define r_neg 4
#define l_pos 3
#define l_neg 2
#define r_speed A0
#define l_speed A1
char var;

void forward() {
  digitalWrite(r_pos, HIGH);
  digitalWrite(r_neg, LOW);
  digitalWrite(l_pos, HIGH);
  digitalWrite(l_neg, LOW);

  analogWrite(r_speed, 200);
  analogWrite(l_speed, 200);
}
void back() {
  digitalWrite(r_pos, LOW);
  digitalWrite(l_neg, HIGH);
  digitalWrite(r_neg, HIGH);
  digitalWrite(l_pos, LOW);
  analogWrite(r_speed, 200);
  analogWrite(l_speed, 200);
}
void right() {
  digitalWrite(r_pos, HIGH);
  digitalWrite(l_neg, LOW);
  digitalWrite(r_neg, LOW);
  digitalWrite(l_pos, HIGH);
  analogWrite(r_speed, 50);
  analogWrite(l_speed, 200);

}
void left() {
  digitalWrite(r_pos, HIGH);
  digitalWrite(l_neg, LOW);
  digitalWrite(r_neg, LOW);
  digitalWrite(l_pos, HIGH);
  analogWrite(r_speed, 200);
  analogWrite(l_speed, 50);
}
void stopp()
{
  digitalWrite(r_pos, LOW);
  digitalWrite(r_neg, LOW);
  digitalWrite(l_pos, LOW);
  digitalWrite(l_neg, LOW);

  analogWrite(r_speed, 0);
  analogWrite(l_speed, 0);

}
void setup() {
  Serial.begin(9600);
  blu.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (blu.available()) 
  {
    String message = blu.readStringUntil('\n');
    message.trim();
    Serial.print(message);
    if (message == "forward") 
    {
      forward();
    }
    else if (message == "back") 
    {
      back();
    }
    else if (message == "right")
    {
      right();
    }
    else if (message == "left") 
    {
      left();
    }
    else if (message == "stop") 
    {
      stopp();
    }
  }
}