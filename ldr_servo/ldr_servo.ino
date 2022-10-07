#include<Servo.h>

int nilaiSensor;
Servo msSG60;
int angle;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  msSG60.attach(3);
  pinMode(3,OUTPUT);
}

void loop() {
  nilaiSensor=analogRead(A0);
  if(nilaiSensor<100){
    angle=0;
  } else if(nilaiSensor<150){
    angle=45;
  } else if(nilaiSensor<200){
    angle=90;
  } else if(nilaiSensor<300){
    angle=135;
  } else {
    angle=180;
  }
  delay(500);
  msSG60.write(angle);
  Serial.println(nilaiSensor);
}
