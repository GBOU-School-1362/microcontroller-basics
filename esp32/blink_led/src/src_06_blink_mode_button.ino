// Пример 6: Кнопка переключает режимы мигания (быстро/медленно)

#define LED_PIN 2
#define BUTTON_PIN 4

int mode = 0; // 0 — медленно, 1 — быстро

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
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Проверяем, нажата ли кнопка
  if (digitalRead(BUTTON_PIN) == LOW) {
    mode = 1 - mode; // Переключаем режим (с 0 на 1 или с 1 на 0)
    delay(300);      // Задержка для устранения дребезга кнопки
  }

  if (mode == 0) {
    blinkLed(1, 500); // Медленный режим
    delay(1000);
  } else {
    blinkLed(3, 150); // Быстрый режим
    delay(500);
  }

  // Почему так? Тут мы учим:
  // - как хранить состояние (mode),
  // - как переключать поведение программы с помощью кнопки,
  // - как применять функции.
  // Это уже основа для создания “умных” устройств, которые реагируют на команды пользователя.
}