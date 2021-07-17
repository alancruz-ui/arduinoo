int rele=8;
//int humedad=9;
void setup() {
  pinMode(rele,OUTPUT);
 
  Serial.begin(9600);
  Serial.print("valor del sensor de humedad:");
}

void loop() {
  int humedad = analogRead(A0);
  Serial.println("lectura:");
  Serial.println(humedad);
  if(humedad>1000){
 digitalWrite(rele, HIGH);
 Serial.println("apagado");
 delay(2000);
    }else if(humedad<1000){
 digitalWrite(rele, LOW);
 Serial.println("encendido");
 delay(2000);
      }

}
