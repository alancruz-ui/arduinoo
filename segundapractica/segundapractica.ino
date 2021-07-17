int ledrojo=2;
int ledama=3;
int ledverde=4;
void setup() {
  pinMode (ledverde,OUTPUT);
  pinMode (ledama,OUTPUT);
  pinMode (ledrojo,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(ledverde, HIGH);
delay(2000);
digitalWrite(ledverde, LOW);
delay(1000);
digitalWrite(ledama, HIGH);
delay(1000);
digitalWrite(ledama, LOW);
delay(1000);
digitalWrite(ledama, HIGH);
delay(1000);
digitalWrite(ledama, LOW);
delay(1000);
digitalWrite(ledama, HIGH);
delay(1000);
digitalWrite(ledama, LOW);
delay(1000);
digitalWrite(ledrojo, HIGH);
delay(2000);
digitalWrite(ledrojo, LOW);
delay(2000);
}
