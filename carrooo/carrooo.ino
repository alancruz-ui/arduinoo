#include <AFMotor.h>

// definir pines y variables
int izquierda = 22;
int derecha = 24;

// definiendo motores
AF_DCMotor motor1(3); 
AF_DCMotor motor2(4);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


void setup() {
  // declaramos tipos de pin
  pinMode(izquierda,INPUT);
  pinMode(derecha,INPUT);
  
 // comenzamos la comunicación en serie
  Serial.begin(9600);
  
}

void loop(){
  // imprimiendo valores de los sensores al monitor serial
  Serial.println(digitalRead(izquierda));  
  Serial.println(digitalRead(derecha));

  // línea detectada por ambos sensores
  
  if(digitalRead(izquierda)==0 && digitalRead(derecha)==0){
    //Avanzamos(Forward)
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
  }
  // línea que detecta el sensor izquierdo
  else if(digitalRead(izquierda)==0 && !digitalRead(derecha)==0){
    //giraramos a la izquierda
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(100);
    motor3.run(BACKWARD);
    motor3.setSpeed(150);
    motor4.run(BACKWARD);
    motor4.setSpeed(150);
    
  }
  // línea detectada por el sensor derecho
  else if(!digitalRead(izquierda)==0 && digitalRead(derecha)==0){
    //se dobla a la derecha
    motor1.run(BACKWARD);
    motor1.setSpeed(150);
    motor2.run(BACKWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
   
  }
  // línea detectada por ninguno
  else if(!digitalRead(izquierda)==0 && !digitalRead(derecha)==0){
    //Alto y se detendra el carrito llegando a la meta o linea fina.  
    motor1.run(LOW);
    motor1.setSpeed(0);
    motor2.run(LOW);
    motor2.setSpeed(0);
    motor3.run(LOW);
    motor3.setSpeed(0);
    motor4.run(LOW );
    motor4.setSpeed(0);
   
  }
  
}
