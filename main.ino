#include <Wire.h>
#include <Encoder.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

Encoder myEnc(2, 3);
int menuIndex = 0;

void setup() {
  lcd.init(); //initialize the lcd
  lcd.backlight();
}

void loop() {
  int val = readEnc(); // readEnc only exits when an input is given
  if (val != 0) { // if the input was the encoder moving then update menuIndex
    menuIndex += val;
    if (menuIndex < 0) menuIndex = 0;
    if (menuIndex > 2) menuIndex = 2;
  } else { // else enter the submenu that was clicked on
    switch (menuIndex)
    {
      case 0:
        myEnc.write(0);
        // call submenu function

      case 1:
        myEnc.write(0);
        // call submenu function

      default:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: Select");
        lcd.setCursor(2, 1);
        lcd.print("Out of Bounds");
  }

    switch (menuIndex) // after exiting the submenu or the menuIndex changing, draw the selected menu item
    {
      case 0:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Test");
        lcd.setCursor(2, 1);
        lcd.print("Menu");

      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Menu");
        lcd.setCursor(2, 1);
        lcd.print("Test");

      default:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: Draw");
        lcd.setCursor(2, 1);
        lcd.print("Out of Bounds");
}

int readEnc() {
  while true {
    if (//button pressed) {
      return 0;
    }

    int val = myEnc.read();
    if (val != 0) {
      myEnc.write(0);
      return val;
    }
  }
}

void calibrateMenu() {
  
}

void grindCapMenu()  {
  
}

void faceCapMenu() {
  
}

void faceChipMenu() {
  
}
