#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "RTClib.h"
RTC_DS3231 RTC;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#define FAN_PIN 3

void setup() {
  Wire.begin();
  RTC.begin();
  lcd.begin();
  lcd.backlight();
  sensors.begin();
    
  pinMode(5, OUTPUT); // инициализируем Pin6 как выход
  pinMode(6, OUTPUT); // инициализируем Pin6 как выход
  pinMode(7, OUTPUT); // инициализируем Pin7 как выход
  pinMode(8, OUTPUT); // инициализируем Pin8 как выход
  pinMode(FAN_PIN, OUTPUT);
  
}

void loop() 
{
   DateTime now = RTC.now();
   
    lcd.setCursor(0, 0);
    lcd.print("Time is: ");
      
    if (now.hour() < 10)
   {
     lcd.print("0");
     lcd.print(now.hour(), DEC);
   }
   else
   {
   lcd.print(now.hour(), DEC);
   }
   lcd.print(":");
   if ( now.minute() < 10)
   {
     lcd.print("0");
     lcd.print(now.minute(), DEC);
   }
   else
   {
   lcd.print(now.minute(), DEC);
   }
   lcd.print(":");
   if ( now.second() < 10)
   {
     lcd.print("0");
     lcd.print(now.second(), DEC);
   }
   else
   {
   lcd.print(now.second(), DEC);
   }
 
 sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 3);
  lcd.print("Temperature: ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("\337C");

      
 if(now.hour() >= 0 && now.hour() < 8)
{
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 lcd.setCursor(0, 1);
 lcd.print("Lights: Off");
 lcd.setCursor(0, 2);
 lcd.print("Compressor: Off");
 }
 
if (now.hour() >= 8 && now.hour() < 22)
{
 digitalWrite(5, HIGH);
 lcd.setCursor(0, 1);
 lcd.print("Lights: On ");
 lcd.setCursor(0, 2);
 lcd.print("Compressor: Off");

 if(temperature >= 26.00)
 {
  analogWrite(FAN_PIN, 255);
 }
 
 if(temperature <= 25.90)
 {
  analogWrite(FAN_PIN, 230);
 }
 
 if(temperature <= 25.80)
 {
  analogWrite(FAN_PIN, 205);
 }
 
 if(temperature <= 25.70)
 {
  analogWrite(FAN_PIN, 180);
 }
 
 if(temperature <= 25.60)
 {
  analogWrite(FAN_PIN, 155);
 }

  if(temperature <= 25.50)
 {
  analogWrite(FAN_PIN, 130);
 }

  if(temperature <= 25.40)
 {
  analogWrite(FAN_PIN, 105);
 }

  if(temperature <= 25.30)
 {
  analogWrite(FAN_PIN, 80);
 }
  
  if(temperature <= 25.20)
 {
  analogWrite(FAN_PIN, 55);
 }

  if(temperature <= 25.10)
 {
  analogWrite(FAN_PIN, 30);
 }

  if(temperature <= 25.00)
 {
  analogWrite(FAN_PIN, 0);
 }
}

if (now.hour() >= 22)
{
 digitalWrite(5, LOW);
 digitalWrite(6, HIGH);
 lcd.setCursor(0, 1);
 lcd.print("Lights: Off");
 lcd.setCursor(0, 2);
 lcd.print("Compressor: On ");
}

if (temperature <= 24.00)
{
digitalWrite(7, HIGH);
}

else
{
digitalWrite(7, LOW);
}

delay(1000);
}
