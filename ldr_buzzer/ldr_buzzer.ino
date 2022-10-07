int dataSensor;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  dataSensor = analogRead(0);
  Serial.println(dataSensor);
  digitalWrite(13,HIGH);  
  tone(8,1000);
  delay(30);
  digitalWrite(13,LOW);
  noTone(8);
  delay(dataSensor);
  
}
