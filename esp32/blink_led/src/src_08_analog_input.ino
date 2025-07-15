// Пример 8: Используем потенциометр для управления яркостью светодиода

#define LED_PIN 2
#define POT_PIN 34 // Любой аналоговый пин ESP32 (например, 34)

const int pwmChannel = 0;
const int pwmFreq = 5000;
const int pwmResolution = 8;

void setup() {
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(LED_PIN, pwmChannel);
}

void loop() {
  // Считываем значение с потенциометра (от 0 до 4095)
  int sensorValue = analogRead(POT_PIN);

  // Преобразуем его к диапазону PWM (0-255)
  int brightness = map(sensorValue, 0, 4095, 0, 255);

  ledcWrite(pwmChannel, brightness);

  delay(10);

  // Почему так? Мы знакомимся с аналоговым вводом — сенсоры, потенциометры, датчики.
  // map() — специальная функция для преобразования диапазона значений.
  // Теперь можно делать “регулятор лампочки” или другие интересные устройства!
}