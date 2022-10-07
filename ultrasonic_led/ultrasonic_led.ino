const int trigPin = 10;
const int echoPin = 9;

const int LED1 = 6;
const int LED2 = 5;
const int LED3 = 4;
const int LED4 = 3;
const int LED5 = 8;
const int LED6 = 7;
const int LED7 = 2;

int duration = 0;
int distance = 0;

void setup() {
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.print(distance);
  Serial.println(" CM");

  if ( distance <= 5 ) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 15 ) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 25 ) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 35 ) {
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 45) {
    digitalWrite(LED5, HIGH);
  } else {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 55 ) {
    digitalWrite(LED6, HIGH);
  } else {
    digitalWrite(LED6, LOW);
  }
  if ( distance > 55 ) {
    digitalWrite(LED7, HIGH);
  } else {
    digitalWrite(LED7, LOW);
  }
  delay(100);
}
