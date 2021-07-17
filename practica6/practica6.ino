//Alan Francisco Cruz de la Cruz practica 6
int ledama=4;
int ledrojo=6;
int ledverde=5;
int zum=7;
float lectura=0;
float sensor=0;
void setup() {
    pinMode(ledama,OUTPUT);
    pinMode(ledrojo,OUTPUT);
    pinMode(ledverde,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  
lectura=analogRead(sensor);
float voltaje=((lectura*5000.0)/1023)/10;
Serial.println(lectura);
delay (500);
if(lectura<61){
digitalWrite(ledverde,HIGH);
}else{
  digitalWrite(ledverde,LOW);
  }
if(lectura>61 && lectura<71){
digitalWrite(ledama,HIGH);
}else{
  digitalWrite(ledama,LOW);
  }
if(lectura>71){
digitalWrite(ledrojo,HIGH);
tone(zum, 220);
delay(500);
}else{
  digitalWrite(ledrojo,LOW);
  noTone(zum);
  delay(500);
  }
 
}
