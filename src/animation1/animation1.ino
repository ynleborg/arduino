/* Arduino example code to display custom characters on I2C character LCD. More info: www.makerguides.com */

// Include the library:
#include <LiquidCrystal_I2C.h>

// Create lcd object of class LiquidCrystal_I2C:
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

// Make custom characters:
byte a[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

byte b[] = {
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000
};

byte c[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte d[] = {
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010
};

byte e[] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001
};

byte f[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};



void setup() {
  // Initialize LCD and turn on the backlight:
  lcd.init();
  lcd.backlight();

  // Create new characters:
  lcd.createChar(0, a);
  lcd.createChar(1, b);
  lcd.createChar(2, c);
  lcd.createChar(3, d);
  lcd.createChar(4, e);
  lcd.createChar(5, f);

  // Clear the LCD screen:
  lcd.clear();

}

// Print all the custom characters:
void loop() {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 15; j++) {
      lcd.write(5);
      lcd.setCursor(j, i);
      for (int k = 0; k <= 4; k++) {
        lcd.write(k);
        lcd.setCursor(j - 1, i);
        delay(10);        
      }
    }
  }
}
