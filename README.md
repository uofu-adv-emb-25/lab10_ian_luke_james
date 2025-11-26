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

For this activity we found that it used a few more mA and we found it to fluctuate between 32mA and 35mA. This means our power consumption is between 160mW and 175mW.

### 3. Blink LED with busy loop

We got 34mA when we fixed the while loop and added a blink statement at the end. We observed that the led was always on visibly as it was blinking fast enough to appear so. We also expected this current to be much larger, but the busy loop is likely not so resource intensive that it makes that much of a difference.

34mA => 170mW of power usage.

### 4. Blink off an interrupt

At 1kHz we see 35mA. At 100kHz we see 35 as well. 2 MHz we see the same at 35mA.

At frequencies above 1KHz we only see 35mA. This was kind of boring so we tested lower frequencies and observed that at 1Hz it fluctuated between 29mA to 31mA. At 100Hz we saw a noticeable current jump from ~30mA to 34mA.

35mA => 175mW

### 5. Sleep Demo

For this part we observed that it started at 18mA for 10 seconds, then went down to 1.2mA for another 10 seconds. This is what we expect as the sleep code is toggling a sleep state every 10 seconds.

### 6. Dormant Demo

We observe 17.8mA when on, 0.8mA when dormant.

17.8mA => 89mW, 0.8mA => 4mW
