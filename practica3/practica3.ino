int led=13;
int boton=7;
void setup() {
   pinMode(led,OUTPUT);
   pinMode(boton,INPUT);
}

void loop() {
  
if(digitalRead(boton)== HIGH){
  digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
    }
}
