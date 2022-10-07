#include<Servo.h>
int trig=8;
int echo=9;
int buzz=10;
int dt=10;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(echo,INPUT);
  servo.attach(11);
  pinMode(11,OUTPUT);
}

void loop() {
  if (distance_count()<60){
    tone(buzz,1000);
    delay(50);
    noTone(buzz);
    delay(distance_count());
  }

  if (distance_count()<10){
    for (int i=0;i<=180;i++){
      servo.write(i);
      delay(1);
    }
    delay(100);
    for (int i=180;i>=0;i--){
      servo.write(i);
      delay(1);
    }
    delay(500);
  }
}

int distance_count(){
  int duration,distance;
  digitalWrite(trig,HIGH);
  delay(dt);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  return distance;
}
