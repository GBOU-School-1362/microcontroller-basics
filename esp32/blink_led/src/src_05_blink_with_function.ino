// Пример 5: Выносим мигание в отдельную функцию

#define LED_PIN 2

// Объявляем свою функцию для мигания светодиодом.
// times — сколько раз мигнуть, interval — пауза между миганиями.
void blinkLed(int times, int interval) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(interval);
    digitalWrite(LED_PIN, LOW);
    delay(interval);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blinkLed(3, 150); // Мигнуть 3 раза с интервалом 150 мс
  delay(2000);      // Подождать 2 секунды

  // Почему так? Функции — это способ разбивать код на части.
  // Становится удобнее читать и переиспользовать код.
  // Всегда стоит выделять повторяющиеся действия в отдельную функцию!
}