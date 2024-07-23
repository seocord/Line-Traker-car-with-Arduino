#define motor1A 8
#define motor1B 9
#define motor2A 10
#define motor2B 11
#define enaPin 7
#define enbPin 6
#define s_Right 5
#define s_Mid 4
#define s_Left 3
int Va = 220;
int Vb = 250;

void setup() 
{
  pinMode(s_Right, INPUT);
  pinMode(s_Mid, INPUT);
  pinMode(s_Left, INPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT); 
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(enaPin, OUTPUT);
  pinMode(enbPin, OUTPUT);
  digitalWrite(enaPin, LOW);
  digitalWrite(enbPin, LOW);
}

void loop() 
{
  
  if((digitalRead(s_Left)==0)&&(digitalRead(s_Mid)==1)&&(digitalRead(s_Right)==0))
  {
    forward();
  }
  if((digitalRead(s_Left)==0)&&(digitalRead(s_Mid)==0)&&(digitalRead(s_Right)==0))
  {
    backfor();
  }
  if((digitalRead(s_Left)==1)&&(digitalRead(s_Mid)==1)&&(digitalRead(s_Right)==1))
  {
    forward();
  }
  if((digitalRead(s_Left)==0)&&(digitalRead(s_Mid)==1)&&(digitalRead(s_Right)==1))
  {
    right1();
  }
  if((digitalRead(s_Left)==0)&&(digitalRead(s_Mid)==0)&&(digitalRead(s_Right)==1))
  {
    right2();
  }
  if((digitalRead(s_Left)==1)&&(digitalRead(s_Mid)==1)&&(digitalRead(s_Right)==0))
  {
    left1();
  }
  if((digitalRead(s_Left)==1)&&(digitalRead(s_Mid)==0)&&(digitalRead(s_Right)==0))
  {
    left2();
  }
  if((digitalRead(s_Left)==1)&&(digitalRead(s_Mid)==0)&&(digitalRead(s_Right)==1))
  {
    forward();
  }
}

void forward()
{
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(enaPin, Va);
  analogWrite(enbPin, Vb); 
}

void backfor()
{
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  analogWrite(enaPin, Va);
  analogWrite(enbPin, Vb);
}
void right1()  //살짝 우회전
{
  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  analogWrite(enaPin, Va);
  analogWrite(enbPin, 0);
}
void right2()  //완전 우회전
{
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  analogWrite(enaPin, Va);
  analogWrite(enbPin, 0);
}
void left1()  //살짝 좌회전
{
  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(enaPin, 0);
  analogWrite(enbPin, Vb);
  Serial.println(3);
}
void left2()  //완전 좌회전
{
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(enaPin, 0);
  analogWrite(enbPin, Vb);
}