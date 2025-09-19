#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Explicitly declare Serial1 and map it to D8 (TX) and D2 (RX)
HardwareSerial Serial1(D2, D8);

// I2C address for the LCD.
LiquidCrystal_I2C lcd(0x27, 16, 2);
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  // Initialize the I2C LCD
  lcd.init();
  lcd.backlight();

  // Start serial communication with the GPS module at 9600 baudrate.
  // The Nucleo's PA9 and PA10 pins correspond to Serial1.
  Serial1.begin(9600);

  Serial.begin(9600);

  lcd.print("STM32 GPS");
  lcd.setCursor(0, 1);
  lcd.print("Position Tracker");
  delay(4000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  GPSDelay(1000);
  unsigned long start;
  double lat_val, lng_val;
  bool loc_valid;

  lat_val = gps.location.lat(); // Gets the latitude
  loc_valid = gps.location.isValid();
  lng_val = gps.location.lng(); // Gets the longitude

  if (!loc_valid) // Executes when invalid data is received from the GPS
  {
    lcd.clear();
    lcd.print("Waiting...");
    Serial.print("Latitude : ");
    Serial.println("*****");
    Serial.print("Longitude : ");
    Serial.println("*****");
    delay(4000);
    lcd.clear();
  }
  else
  {
    lcd.clear();
    Serial.println("GPS READING: ");
    Serial.print("Latitude : ");
    Serial.println(lat_val, 6);
    lcd.setCursor(0, 0);
    lcd.print("LAT:");
    lcd.print(lat_val, 6);
    Serial.print("Longitude : ");
    Serial.println(lng_val, 6);
    lcd.setCursor(0, 1);
    lcd.print("LONG:");
    lcd.print(lng_val, 6);
    delay(4000);
  }
}

static void GPSDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    // The GPS module is connected to Serial2
    while (Serial1.available())
      gps.encode(Serial1.read());
  } while (millis() - start < ms);
}
