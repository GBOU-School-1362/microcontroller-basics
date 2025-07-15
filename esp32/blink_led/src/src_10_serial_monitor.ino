// Пример 10: Выводим данные в Serial Monitor (монитор порта)

#define POT_PIN 34

void setup() {
  Serial.begin(115200); // Запускаем монитор порта на скорости 115200
}

void loop() {
  int value = analogRead(POT_PIN); // Читаем значение с потенциометра

  Serial.print("Analog value: ");
  Serial.println(value); // Выводим значение в монитор

  delay(500);

  // Почему так? Serial Monitor — это ваш “глаз” внутрь микроконтроллера.
  // Можно узнать, что происходит, отлаживать программы, выводить любые данные!
}