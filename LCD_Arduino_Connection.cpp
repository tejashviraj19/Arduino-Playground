#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("How you doin'?");
  delay(1000);
  
  // Scroll the content to the right
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // Scroll one position Left
    lcd.scrollDisplayLeft();
    // Wait a bit
    delay(150);
  }
  
  // Clear the screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Count:");
}

void loop() {
  lcd.setCursor(6, 0);
  // Print the number of seconds since reset
  lcd.print(millis() / 1000);
}
