# Lab 10

## Activity 0

- Wake_en default value = 0xFFFFFFFF
- Sleep_en default value = 0xFFFFFFFF
- Enabled default value = 0x0

## Activity 1

### 1. Blink an LED with sleep_ms

For this activity we found that we were using, on average, 30mA.
This means that the power usage = 5V \* 30mA = 150mW.

### 2. Blink an LED using FreeRTOS Thread

For this activity we found that it used a few more mA and we found it to fluctuate between 32mA and 35mA. This means our power consumption is between 160mA and 175mA.

### 3. Blink LED with busy loop

### 4. Blink off an interrupt

### 5. Sleep Demo

### 6. Dormant Demo
