const int BUTTON = 3;
const int LED = 5;
const int BUZZER = 2;
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
      if(j==1){ j=1000; tone(BUZZER,j+1000); }
      tone(BUZZER, j+1000);
      Serial.println(j);
      delay(100);
    }
  } else {
    for(int i=1;i<=100;i++){
      analogWrite(LED, i);
      tone(BUZZER, i+1000);
      Serial.println(i);
      delay(15);
    }
    for(int i=99;i>=0;i--){
      analogWrite(LED, i);
      tone(BUZZER, i+1000);
      delay(15);
    }
  }
}
