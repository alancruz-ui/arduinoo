int VALOR;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   VALOR=analogRead(A0);
   Serial.println(VALOR);
   delay(500);
}
