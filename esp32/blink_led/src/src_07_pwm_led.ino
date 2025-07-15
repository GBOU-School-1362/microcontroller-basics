// Пример 7: Регулировка яркости светодиода с помощью ШИМ (PWM)

#define LED_PIN 2

// Для ESP32 нужно выбрать канал и частоту ШИМ
const int pwmChannel = 0;
const int pwmFreq = 5000; // 5 кГц — стандартное значение для светодиодов
const int pwmResolution = 8; // 8 бит: значения от 0 до 255

void setup() {
  // Настраиваем ШИМ на выбранном пине
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(LED_PIN, pwmChannel);
}

void loop() {
  // Увеличиваем яркость постепенно
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle += 5) {
    ledcWrite(pwmChannel, dutyCycle); // Задаём уровень ШИМ (яркость)
    delay(20);
  }
  // Уменьшаем яркость обратно
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle -= 5) {
    ledcWrite(pwmChannel, dutyCycle);
    delay(20);
  }
  // Почему так? Это показывает, как плавно менять яркость светодиода с помощью PWM.
  // PWM нужен для управления не только светодиодами, но и моторами, звуком и многим другим!
}