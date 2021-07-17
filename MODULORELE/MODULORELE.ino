int rele = 8;
 void setup(){
 pinMode(rele, OUTPUT);
 Serial.begin(9600);
 } void loop(){
 digitalWrite(rele, HIGH);
 Serial.println("apagado");
 delay (2000);
 digitalWrite(rele, LOW);
 Serial.println("encendido");
 delay (2000);
 }  
 
