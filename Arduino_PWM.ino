#define LED_PIN 3 // задаем имя для Pin3

void setup() // процедура setup
{
    pinMode(LED_PIN, OUTPUT); // инициализируем Pin3 как выход
}

void loop() // процедура loop
{
 // плавное включение светодиода
 // начальное значение на Pin6 i=0, если i<=255, то прибавляем к i единицу
  for(int i=0;i<=255;i++)
{
  analogWrite(LED_PIN, i);
  delay(1000); // ставим задержку для эффекта
}
delay(49887000); // ставим паузу в 0,5 секунды

 //плавное затухание светодиода
 // начальное значение на Pin3 i=255, если i>=255, то вычитаем от i единицу
  for(int i=255;i>=0;i--)
{
  analogWrite(LED_PIN, i);
  delay(1000); // ставим задержку для эффекта
}
delay(49887000); // ставим паузу в 0,5 секунды
}
