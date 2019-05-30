// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int state = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
  scr1();
}

void loop() {
  Serial.println(digitalRead(7));
  if (digitalRead(7) == LOW) {
    state = !state;
    lcd.clear();
    delay(100);
    if (state == 0) {
      scr1();
    }
    else {
      scr2();
    }
  }
}
 
void scr1() {
	//lcd.setCursor(0, 0);
  	lcd.print("Temperature: 22C");  
  	lcd.setCursor(0, 1);
  	lcd.print("Humidity: 10%");	
}
void scr2() {
	//lcd.setCursor(0, 0);
  	lcd.print("Water: 2L");
  	lcd.setCursor(0, 1);
	lcd.print("Oxygen: 22%");
}
