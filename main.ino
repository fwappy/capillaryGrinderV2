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
    if (menuIndex > 1) menuIndex = 1;
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
        myEnc.write(0);
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
        lcd.print("Error: Scroll");
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
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Test");
  lcd.setCursor(2, 1);
  lcd.print("Menu");
  
  int subMenuIndex = 0;
  while true {
    int val = readEnc(); // readEnc only exits when an input is given
  if (val != 0) { // if the input was the encoder moving then update menuIndex
    subMenuIndex += val;
    if (subMenuIndex < 0) subMenuIndex = 0;
    if (subMenuIndex > 1) subMenuIndex = 1;
  } else { // else enter the submenu that was clicked on
    switch (subMenuIndex)
    {
      case 0:
        myEnc.write(0);
        // call submenu function

      case 1:
        myEnc.write(0);
        // call submenu function

      default:
        myEnc.write(0);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: Select");
        lcd.setCursor(2, 1);
        lcd.print("Out of Bounds");
  }

    switch (subMenuIndex) // after exiting the submenu or the menuIndex changing, draw the selected menu item
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
        lcd.print("Error: Scroll");
        lcd.setCursor(2, 1);
        lcd.print("Out of Bounds");
  }
}

void grindCapMenu()  {
  int subMenuIndex = 0;
}

void faceCapMenu() {
  int subMenuIndex = 0;
}

void faceChipMenu() {
  int subMenuIndex = 0;
}
