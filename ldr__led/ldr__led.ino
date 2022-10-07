int inputSensor;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT); 
}

void loop() {
  inputSensor=analogRead(0); 
  if (inputSensor<800) {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
  } else digitalWrite(13,HIGH), digitalWrite(12,LOW);
  
  Serial.println(inputSensor);
  delay(100);
}
