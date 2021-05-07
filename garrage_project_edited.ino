#include<Servo.h>
Servo myservo;
int trigpin=13;
int echopin=7;
void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  myservo.attach(4);
}

void loop()
{
  digitalWrite(trigpin,HIGH);
  delay(1000);
   digitalWrite(trigpin,LOW);
  int duration=pulseIn(echopin,HIGH);
  int distance=(duration*0.034)/2;
  Serial.print("the distance of the car is");
  Serial.println(distance);
  
  if(distance>20)
  {

   myservo.write(0);
  Serial.println("servo is at angle 0");
    delay(1000);
  
  }
  else if(distance<20)
  {
  myservo.write(90);
  Serial.println("servo is at angle 90");
  delay(1000);  
}
 delay(1000);
}
