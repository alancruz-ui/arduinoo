int derecha =A8;
int izquierda= A9;

#include "AFMotor.h"

AF_DCMotor motor1(3);
AF_DCMotor motor2(4); 
int enderecha;
int enizquierda; 
void setup() { 
  
  // Se indica que ese pin va a utilizarse para recibir información 
  pinMode(izquierda, INPUT);  
  pinMode(derecha,INPUT);
  // Se activa el monitor serie para mostrar información posteriormente 
  Serial.begin(9600); 
 
} 
 
void loop() { 
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  // Se lee la información ofrecida por el sensor 
   enderecha = analogRead(derecha); 
  Serial.println(enderecha);
  Serial.print("");
  enizquierda=analogRead(izquierda);
  Serial.println(enizquierda);

  if(enderecha>40){
     if(enizquierda>40){
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      }else{
          motor1.run(FORWARD);
          motor2.run(RELEASE);
        }
    }
 if(enderecha<40){
  if(enizquierda>40){
     motor2.run(FORWARD);
     motor1.run(RELEASE);
    }
    else{
       
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      }
     
  
  }
} 
