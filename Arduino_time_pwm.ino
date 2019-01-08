#include "RTClib.h"
RTC_DS3231 RTC;
#define LED_PIN 3 // задаем имя для Pin3


void setup() // процедура setup
{
    pinMode(LED_PIN, OUTPUT); // инициализируем Pin3 как выход
    RTC.begin();
}

void loop()
{
if (now.hour() >= 8 && now.minute() >= 0)
{
 for(int i=0;i<=255;i++)
{
  analogWrite(LED_PIN, i);
  delay(1000); // ставим задержку для эффекта
}
}

  
else if (now.hour() == 21 && now.minute() == 45)
{
for(int i=255;i>=0;i--)
{
  analogWrite(LED_PIN, i);
  delay(1000); // ставим задержку для эффекта
}
}
}
