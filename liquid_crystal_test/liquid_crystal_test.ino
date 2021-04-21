#include <LiquidCrystal_I2C.h>

#include <Wire.h>

// initialize the liquid crystal library
// the first parameter is the I2C address
// the second parameter is how many rows are on your screen
// the third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);
int xPos = 0;
int yPos = 0;
double arm_ha = 97.2;
double arm_ba = 72;

void setup() {

    // initialize lcd screen
    lcd.init();
    // turn on the backlight
    lcd.backlight();
    Serial.begin(9600);
    lcd.setCursor(0,0);
    lcd.print("You sent me:");
}

// void loop() {
//   // scroll 13 positions (string length) to the left
//   // to move it offscreen left:
//   for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
//     // scroll one position left:
//     lcd.scrollDisplayLeft();
//     // wait a bit:
//     delay(150);
//   }

//   // scroll 29 positions (string length + display length) to the right
//   // to move it offscreen right:
//   for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
//     // scroll one position right:
//     lcd.scrollDisplayRight();
//     // wait a bit:
//     delay(250);
//   }

//   // scroll 16 positions (display length + string length) to the left
//   // to move it back to center:
//   for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
//     // scroll one position left:
//     lcd.scrollDisplayLeft();
//     // wait a bit:
//     delay(250);
//   }

//   // delay at the end of the full loop:
//   delay(1000); 

// }


void loop() {
    // when characters arrive over the serial port...
    
    if (Serial.available()) {
        // wait a bit for the entire message to arrive        
        // clear the screen
        
        
        // read all the available characters
        while (Serial.available() > 0) {
            // display each character to the LCD
            String data = Serial.readStringUntil('\n');
            lcd.setCursor(0,0);
            lcd.print("You sent me:");
            
            lcd.setCursor(0,1);
            lcd.print("                ");
            
            lcd.setCursor(0,1);
            Serial.println(data);
            lcd.print(data);
        }
        //delay(2000);
        //lcd.clear();
    }
}

/*
void loop() {
    // wait for a second
    delay(1000);
    // tell the screen to write on the top row
    lcd.setCursor(0, 0);
    // tell the screen to write “hello, from” on the top row
    lcd.print("Xpos=");
    lcd.print(xPos);

    // tell the screen to write on the bottom row
    lcd.setCursor(8, 0);
    // tell the screen to write “Arduino_uno_guy” on the bottom row
    // you can change whats in the quotes to be what you want it to be!
    lcd.print("Ypos=");
    lcd.print(yPos);

    lcd.setCursor(0,1);
    lcd.print("B=");
    lcd.print(arm_ba);

    lcd.setCursor(8,1);
    lcd.print("H=");
    lcd.print(arm_ha);

    xPos+=10;
    yPos+=10;
}
*/
