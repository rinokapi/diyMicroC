void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {  
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(10000);

  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(8000);

  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(7000);

  tone(10, 1000);
  delay(1000);
  noTone(10);
  delay(1000);
  tone(10, 1000);
  noTone(10);
}
