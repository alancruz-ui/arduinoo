

#include <Servo.h>
int S0 2
int S1 3
int S2 5
int S3 4
int  salidaSensor 6
int led1=22;
int led2=24;
int led3=26;
Servo ServoArriba;
Servo ServoAbajo;
int frecuencia = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(salidaSensor, INPUT);
  //20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  ServoArriba.attach(8);
  ServoAbajo.attach(9);
  Serial.begin(9600);
}
void loop() {
  ServoArriba.write(50);
  delay(500);
  
  for(int i = 50; i < 130; i++) {
    ServoArriba.write(i);
    delay(2);
  }
  delay(500);
  
  color = leerColor();
  delay(10);  
  switch (color) {
    case 1:
    ServoAbajo.write(50);
    break;
    case 2:
    ServoAbajo.write(120);
    break;
    case 3:
    ServoAbajo.write(175);
    break;
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 130; i < 160; i++) {
    ServoArriba.write(i);
    delay(2);
  } 
  delay(2000);
  
  for(int i = 160; i >50; i--) {
    ServoArriba.write(i);
    delay(2);
  }
  color=0;
}
int leerColor() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frecuencia = pulseIn(salidaSensor, LOW);
  int Rojo = frecuencia;
  Serial.print("R= ");
  Serial.print(frecuencia);
  Serial.print("rojo");
  Serial.print("  ");
  delay(50);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frecuencia = pulseIn(salidaSensor, LOW);
  int Verde = frecuencia;
  Serial.print("G= ");
  Serial.print(frecuencia);
  Serial.print("verde");
  Serial.print("  ");
  delay(50);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frecuencia= pulseIn(salidaSensor, LOW);
  int Azul = frecuencia;
  Serial.print("B= ");
  Serial.print(frecuencia);
   Serial.print("azul");
  Serial.println("  ");
  delay(50);
  if(Rojo<Verde && Rojo<Azul){
    color = 1; 
    Serial.print("rojo");
  digitalWrite(led1, HIGH);                               
  delay(1000);                     
  digitalWrite(led1, LOW); 
  delay(1000);    
  }
  if(Rojo<Azul && Verde<Azul){
    color = 2; 
    Serial.print("verde");
    digitalWrite(led2, HIGH);                               
  delay(1000);                     
  digitalWrite(led2, LOW); 
  delay(1000); 
  }
  if (Azul<Rojo && Azul<Verde){
    color = 3; 
    Serial.print("azul");
    digitalWrite(led3, LOW);                               
  delay(1000);                     
  digitalWrite(led3, LOW); 
  delay(1000); 
  }
  return color;  
}
