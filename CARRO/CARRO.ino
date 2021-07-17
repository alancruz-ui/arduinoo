

#include "AFMotor.h"

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
void setup() {
 motor1.setSpeed(100);
 motor2.setSpeed(100);

}

void loop() {
  // put your main code here, to run repeatedly:
   motor1.run(BACKWARD);
   motor2.run(FORWARD);
}
