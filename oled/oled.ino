#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
int state = 0;

Adafruit_SSD1306 display(-1);

void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT_PULLUP);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (digitalRead(9) == LOW) {
    state = !state;
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
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temperature: 20.0 C");
  display.setCursor(0, 10);
  display.print("Moisture: 20.0%");
  display.setCursor(0, 20);
  display.print("Soil Moisture: 45.2%");
  display.display();
}

void scr2() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Light Strength: 20%");
  display.setCursor(0, 10);
  display.print("Pump: [*]");
  display.display();
}
