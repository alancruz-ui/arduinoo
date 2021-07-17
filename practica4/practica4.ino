//Alan Francisco cruz de la Cruz
 led=6;
int foto=0;
int lectura=0;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  lectura=analogRead(foto);
  Serial.println(lectura);
  if(lectura<42){
    digitalWrite(led,HIGH);
    }else{
      
      digitalWrite(led,LOW);
      }
}
