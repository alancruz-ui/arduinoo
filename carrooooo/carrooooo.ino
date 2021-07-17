#include<AFMotor.h>
AF_DCMotor M3(3);
AF_DCMotor M4(4);
int a=0;
int b=1;
int velocidad=110;
int sensorI=22;
int lecturaI=0;
int sensorD=24;
int lecturaD=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
M3.run(RELEASE);
M4.run(RELEASE);
delay(1000);
}

void loop() {
  lecturaI=digitalRead(sensorI);
  lecturaD=digitalRead(sensorD);
Serial.println("sensor izquierdo");
Serial.println(lecturaI);
Serial.println("sensor derecho");
Serial.println(lecturaD);
  // put your main code here, to run repeatedly:
if(digitalRead(sensorI)&&digitalRead(sensorD)){
   M3.setSpeed(100);
   M4.setSpeed(100);
   M3.run(BACKWARD);
   M4.run(BACKWARD);
   delay(100);
   a=0;
  }
  else if(!digitalRead(sensorD)&& digitalRead(sensorI))
  {
    a=1;
    M3.setSpeed(150);
    M4.setSpeed(150);
    M3.run(BACKWARD);
    M4.run(BACKWARD);
    delay(20);
    M3.setSpeed(100);
    M4.setSpeed(100);
    M3.run(FORWARD);
    M4.run(BACKWARD);
    delay(50);
    M3.setSpeed(200);
    M4.setSpeed(200);
    M3.run(FORWARD);
    M4.run(BACKWARD);
    delay(50);
    M3.setSpeed(250);
    M4.setSpeed(250);
    M3.run(FORWARD);
    M4.run(BACKWARD);
    delay(70);
    }
    else if(digitalRead(sensorD)&& !digitalRead(sensorI)) {
      a=1;
      M3.setSpeed(150);
      M4.setSpeed(150);
      M3.run(BACKWARD);
      M4.run(BACKWARD);
      delay(20);
      M3.setSpeed(100);
      M4.setSpeed(100);
      M3.run(BACKWARD);
      M4.run(FORWARD);
      delay(50);
      M3.setSpeed(200);
      M4.setSpeed(200);
      M3.run(BACKWARD);
      M4.run(FORWARD);
      delay(50);
      M3.setSpeed(250);
      M4.setSpeed(250);
      M3.run(BACKWARD);
      M4.run(FORWARD);
      delay(70);
      }
      else{
        b=1;
        }
        if(a==1 &&  b==1){
          a=0;
          b=0;
          M3.setSpeed(100);
          M4.setSpeed(100);
          M3.run(FORWARD);
          M4.run(FORWARD);
          delay(100);
          M3.setSpeed(100);
          M4.setSpeed(100);
          M3.run(RELEASE);
          M4.run(RELEASE);
          delay(10);
          }
          if(b==1 && a==0){
            
            M3.setSpeed(110);
            M4.setSpeed(110);
            M3.run(FORWARD);
            M4.run(FORWARD);
            delay(20);
            M3.setSpeed(100);
            M4.setSpeed(100);
            M3.run(FORWARD);
            M4.run(FORWARD);
            delay(5);
            }
}
