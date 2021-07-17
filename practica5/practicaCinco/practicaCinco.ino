//Alan Francisco cruz de la cruz
int led=6;
float lectura=0;
float sensor=0;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  
lectura=analogRead(sensor);
float voltaje=((lectura*5000.0)/1023)/10;
Serial.println(lectura);
delay (500);
if(lectura>60){
digitalWrite(led,HIGH);
}else{
  digitalWrite(led,LOW);
  }

}
