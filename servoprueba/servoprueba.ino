#include <Servo.h>
Servo servo;
Servo servo2;
void setup() {
  // put your setup code here, to run once:
 servo.attach(8);
 servo2.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
 servo.write(50);
 delay(2000);
  servo.write(130);
 delay(2000);
 servo.write(160);
 delay(2000);
  servo2.write(50);
  delay(2000);
   servo2.write(90);
  delay(2000);
   servo2.write(150);
  delay(2000);
}
