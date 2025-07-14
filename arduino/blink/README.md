# Arduino Blink Example

**Описание:**  
Пример мигания встроенным светодиодом на Arduino.

## Как использовать:
1. Откройте файл `sketch.ino` в Arduino IDE.
2. Загрузите скетч на плату Arduino (Uno, Nano, и т.д.).
3. Светодиод должен мигать с интервалом 1 секунда.

## Код: sketch.ino
```
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```