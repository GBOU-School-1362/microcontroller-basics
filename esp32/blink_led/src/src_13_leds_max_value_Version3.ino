// Пример 13: Используем функцию с возвращаемым значением и массив для поиска самого "старшего" светодиода

/*
  Допустим, у нас есть массив с "уровнем яркости" для каждого светодиода (например, если бы мы управляли PWM).
  Мы хотим найти, какой светодиод должен загореться ярче всего.
  Для этого используем функцию, возвращающую индекс светодиода с максимальным значением.
*/

#define NUM_LEDS 3
int ledPins[NUM_LEDS] = {2, 4, 15};
int brightness[NUM_LEDS] = {120, 255, 80}; // Пример "уровней яркости" (0-255)

// Функция поиска индекса максимального значения в массиве
int findMaxIndex(int arr[], int length) {
  int maxIdx = 0;
  for (int i = 1; i < length; i++) {
    if (arr[i] > arr[maxIdx]) {
      maxIdx = i;
    }
  }
  return maxIdx;
}

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Для ESP32 настраиваем PWM на всех пинах
  for (int i = 0; i < NUM_LEDS; i++) {
    ledcSetup(i, 5000, 8);
    ledcAttachPin(ledPins[i], i);
  }
}

void loop() {
  int idx = findMaxIndex(brightness, NUM_LEDS); // Находим индекс самого яркого

  // Включаем только этот светодиод на максимальную яркость, остальные выключаем
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i == idx) {
      ledcWrite(i, 255); // максимум
    } else {
      ledcWrite(i, 0); // выключаем
    }
  }
  delay(1000);

  // Меняем массив яркости для демонстрации (циклический сдвиг)
  int temp = brightness[0];
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    brightness[i] = brightness[i + 1];
  }
  brightness[NUM_LEDS - 1] = temp;
}