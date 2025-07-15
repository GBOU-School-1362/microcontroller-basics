// Пример 9: Светофор — управление тремя светодиодами

#define RED_PIN    15  // Подключите красный светодиод
#define YELLOW_PIN 2   // Жёлтый (можно встроенный)
#define GREEN_PIN  4   // Зелёный

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // Красный свет
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  delay(2000);

  // Жёлтый свет
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(1000);

  // Зелёный свет
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(2000);

  // Жёлтый перед красным
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(1000);

  // Почему так? Это упражнение учит работать с несколькими выходами и создавать простые “автоматические” устройства.
  // Можно расширять: добавить кнопку “пешеход”, сделать мигалки и т.д.
}