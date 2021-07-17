#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,1,0);

void setup() {
 lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("hola, han pasado");
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  lcd.print(" seg.");

}
