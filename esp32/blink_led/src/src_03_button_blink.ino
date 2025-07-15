// Пример 3: Добавляем кнопку для управления миганием

#define LED_PIN 2
#define BUTTON_PIN 4    // Подключите кнопку к пину 4 и GND

int blinkDelay = 300;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Кнопка подключена к пину 4 и земле (GND).
  // Включаем внутренний подтягивающий резистор (INPUT_PULLUP),
  // чтобы пин был "HIGH" без нажатия и "LOW" при нажатии кнопки.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Считываем состояние кнопки
  int buttonState = digitalRead(BUTTON_PIN);

  // Если кнопка нажата (LOW):
  if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);
    delay(blinkDelay);
    digitalWrite(LED_PIN, LOW);
    delay(blinkDelay);
  } else {
    // Если кнопка не нажата — светодиод не мигает, просто выключен
    digitalWrite(LED_PIN, LOW);
  }

  // Почему так? Мы учимся работать с вводом — читать состояния кнопки.
  // Это основа для создания интерактивных устройств.
  // Использование INPUT_PULLUP позволяет не использовать внешний резистор.
}