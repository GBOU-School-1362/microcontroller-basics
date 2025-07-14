# Raspberry Pi Blink Example

**Описание:**  
Пример мигания светодиодом на Raspberry Pi через GPIO.

## Как использовать:
1. Подключите светодиод к GPIO18 (через резистор).
2. Установите Python и библиотеку RPi.GPIO:  
   `pip install RPi.GPIO`
3. Запустите скрипт `blink.py`:
   ```
   python3 blink.py
   ```
4. Светодиод будет мигать с интервалом 1 секунда.

## Код: blink.py
```python
import RPi.GPIO as GPIO
import time

LED_PIN = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(LED_PIN, GPIO.LOW)
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
```