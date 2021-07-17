int trig=9;
int eco=8;
int ledama=4;
int ledrojo=6;
int duracion;
int distancia;
int zum =7;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(eco,INPUT);
  pinMode(ledama,OUTPUT);
  pinMode(ledrojo,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duracion=pulseIn(eco,HIGH);
  distancia=duracion / 58.2;
  delay(200);
  if(distancia>0 && distancia <5){
    digitalWrite(ledrojo,HIGH);
    Serial.println("estas a 5 cm");
    tone(zum, 220);
    delay(200);
    digitalWrite(ledrojo, LOW);
    noTone(zum);
    delay(500);
    }
  if(distancia>5 && distancia <10){
    digitalWrite(ledama,HIGH);
    Serial.println("estas a 10 cm");
    tone(zum, 400);
    delay(500);
    digitalWrite(ledama, LOW);
    noTone(zum);
    delay(500);
    }

}
