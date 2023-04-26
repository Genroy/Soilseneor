int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
// declare the ledPin as an OUTPUT:
Serial.begin(9600);
delay(500);
  /*lcd.begin();
  lcd.print("Hi everybody)");
        lcd.setCursor(0, 1);
        lcd.print("My Name's Kaz"); */
}

void loop() {
// read the value from the sensor:
sensorValue = analogRead(sensorPin);
sensorValue = map(sensorValue, 0, 1023, 0, 100);

lcd.begin();
  lcd.print("sensor");
        lcd.setCursor(0, 1);
        lcd.print(sensorValue);
        lcd.print(" % ");
        delay(500);
//Serial.print("sensor = " );
//Serial.println(sensorValue);


}
