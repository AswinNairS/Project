#include <SoftwareSerial.h>
 
const int trigPin1 = A1;
 
const int echoPin1 = A0;
 
long duration1;
 
int distance1;
 
void setup()
 
{
 
pinMode(trigPin1, OUTPUT); 
 
pinMode(echoPin1, INPUT);
 
pinMode(5, OUTPUT);
 
pinMode(A4, INPUT);
 
Serial.begin(9600);
 
 
}
 
void loop()
 
{
 
digitalWrite(trigPin1, LOW);
 
delayMicroseconds(2);
 
digitalWrite(trigPin1, HIGH);
 
delayMicroseconds(10);
 
digitalWrite(trigPin1, LOW);
 
duration1 = pulseIn(echoPin1, HIGH);
 
distance1= duration1*0.034/2;
 
Serial.print("Distance1: ");
 
Serial.println(distance1);
 
if (distance1<=20){
 
  digitalWrite(5, HIGH);
 
delay(1500);
 
digitalWrite(5, LOW);
 
digitalWrite(5, HIGH);
 
delay(1500);
 
 
}
 
else if (distance1<=15){
 
digitalWrite(5, HIGH);
 
delay(1500);
 
digitalWrite(5, LOW);
 
digitalWrite(5, HIGH);
 
delay(1500);
 
delay(500);

 
}
 
else
 
digitalWrite(5, LOW);
 
int sensorValue = digitalRead(A4);
 
if (sensorValue==1){
 
  //digitalWrite(5, HIGH);
  tone(5, 329);
 
delay(100);
 
//digitalWrite(5, LOW);
 noTone(5);
//digitalWrite(5, HIGH);
 tone(5, 329);
delay(1500);
 
}
 
else
 
//digitalWrite(5, LOW);
 noTone(5);
}
