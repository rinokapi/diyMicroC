const int BUTTON = 2;
const int LED = 5;
int BUTTONstate = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  BUTTONstate = digitalRead(BUTTON);
  if (BUTTONstate == HIGH) {
    for(int j=0;j<=1;j++){
      digitalWrite(LED, j);
      Serial.println(j);
      delay(100);
    }
  } else {
    for(int i=1;i<=100;i++){
      analogWrite(LED, i);
      Serial.println(i);
      delay(15);
    }
    for(int i=99;i>=0;i--){
      analogWrite(LED, i);
      delay(15);
    }
    delay(500);
  }
}
