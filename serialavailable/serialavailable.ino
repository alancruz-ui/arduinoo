//05/08/2020
// alan francisco cruz de la cruz
String dato;
int ledrojo=11;
String encendido="encender";
String apagado="apagar";
void setup() {
    Serial.begin(9600);
    pinMode(ledrojo, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    //lee
    dato=Serial.readStringUntil('\n');
   
   if(dato == encendido){
    Serial.println("led encendido");
    digitalWrite(ledrojo,HIGH);
    
    }else if( dato == apagado){
      Serial.println("led apagado");
    digitalWrite(ledrojo,LOW);
      }else{
        Serial.println("invalido");
        }
  }
  

}
