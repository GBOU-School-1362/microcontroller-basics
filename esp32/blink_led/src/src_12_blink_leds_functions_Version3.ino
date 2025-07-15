// Пример 12: Используем массивы и функции для управления светодиодами

/*
  Мы создаём функцию, которая мигает сразу всеми светодиодами из массива.
  Функция получает массив и его размер в качестве параметров.
*/

#define NUM_LEDS 3

int ledPins[NUM_LEDS] = {2, 4, 15}; // Массив пинов

// Функция для мигания всеми светодиодами
void blinkAllLeds(int pins[], int length, int interval) {
  for (int i = 0; i < length; i++) {
    digitalWrite(pins[i], HIGH);
  }
  delay(interval);
  for (int i = 0; i < length; i++) {
    digitalWrite(pins[i], LOW);
  }
  delay(interval);
}

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  blinkAllLeds(ledPins, NUM_LEDS, 500); // Мигаем всеми сразу

  // Для разнообразия: поочередно мигаем каждым светодиодом
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
    delay(200);
  }
}