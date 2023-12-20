#include <Wire.h>
#include <Encoder.h>

#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

Encoder myEnc(2, 3);
int menu_index = 0;

void setup() {
  lcd.init(); //initialize the lcd
  lcd.backlight();
}

void loop() {
  int val = myEnc.read();
  if (val != 0) {
    menu_index += val;
    if (menu_index < 0) menu_index = 0;
    if (menu_index > 2) menu_index = 2;
    
    lcd.clear();                 // clear display
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("Test");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (2, 1)
    lcd.print("Menu"); // print message at (2, 1)
    
    delay(50);
  }
}
