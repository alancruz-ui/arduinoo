int potenciometro=0;
int ledrojo= 11;
int val;
int med;
void setup() {
  pinMode(ledrojo,OUTPUT);
  Serial.begin(9600);
  pinMode(potenciometro,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(potenciometro);
  med=map(val,0,1023,0,100);
  analogWrite(ledrojo,med);

}
