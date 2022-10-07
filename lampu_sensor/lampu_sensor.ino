const int pinBuzzer = 2;
int state=0;
long cm, duration, distance;
void setup() {
  Serial.begin(9600); 
  pinMode(8, INPUT); //pin Digital untuk Echo Relay
  pinMode(9, OUTPUT);//pin Digital untuk Triger
  pinMode(13, OUTPUT);//pin Digital untuk Vin Relay
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(8, LOW);//posisi low untuk echo pada relay
  digitalWrite(9, LOW);//posisi low untuk triger pada relay
  

}

void measureDistance() { //funcation untuk mengatur jarak sensor ultrasonic
     digitalWrite(9, HIGH);
     delayMicroseconds(5);
     digitalWrite(9, LOW);
     delayMicroseconds(5);
     duration=pulseIn(8, HIGH);
     distance=(duration/2)/29,1;
     cm = microsecondsToCentimeters(distance);
}
void loop() {
  measureDistance();
  Serial.print(distance);
  Serial.print(" OK ");

 if (){
  digitalWrite(pinBuzzer, HIGH);
  digitalWrite(13, LOW);
  delay(1000);
  }
  else {
  digitalWrite(pinBuzzer, LOW);
  digitalWrite(13, HIGH);}
  delay(1000);
}

  
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
}
