// Пример 14: Более сложная логика — если кнопка нажата, мигают все светодиоды, иначе поочередно

#define NUM_LEDS 3
#define BUTTON_PIN 18

int ledPins[NUM_LEDS] = {2, 4, 15};

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void blinkAllLeds(int interval) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(interval);
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(interval);
}

void blinkLedsSequentially(int interval) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(interval);
    digitalWrite(ledPins[i], LOW);
    delay(interval);
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    blinkAllLeds(150); // Если кнопка нажата — все мигают вместе
  } else {
    blinkLedsSequentially(100); // Иначе мигают по очереди
  }
}