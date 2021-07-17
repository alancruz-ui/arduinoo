

#include <Servo.h>
#define S0 2
#define S1 3
#define S2 5
#define S3 4
#define sensorOut 6
int led1=22;
int led2=24;
int led3=26;
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(8);
  bottomServo.attach(9);
  Serial.begin(9600);
}
void loop() {
  topServo.write(50);
  delay(500);
  
  for(int i = 50; i < 130; i++) {
    topServo.write(i);
    delay(2);
  }
  delay(500);
  
  color = readColor();
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(50);
    break;
    case 2:
    bottomServo.write(75);
    break;
    case 3:
    bottomServo.write(100);
    break;
    case 4:
    bottomServo.write(125);
    break;
    case 5:
    bottomServo.write(150);
    break;
    case 6:
   bottomServo.write(175);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 130; i < 160; i++) {
    topServo.write(i);
    delay(2);
  } 
  delay(2000);
  
  for(int i = 160; i >50; i--) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}
// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("rojo");
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("verde");
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
   Serial.print("azul");
  Serial.println("  ");
  delay(50);
  if(R<G && R<B){
    color = 1; // Red
    Serial.print("rojo");
  digitalWrite(led1, HIGH);                               
  delay(1000);                     
  digitalWrite(led1, LOW); 
  delay(1000);    
  }
  if(R<B && G<B){
    color = 3; // Green
    Serial.print("verde");
  }
  if (B<R && B<G){
    color = 6; // Blue+
    Serial.print("azul");
  }
  return color;  
}
