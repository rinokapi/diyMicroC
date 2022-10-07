#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(3);
}

void loop() {
  servo.write(10);
  delay(1000);
  servo.write(100);
  delay(1000);
}
