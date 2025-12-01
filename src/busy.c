/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma GCC optimize ("O0")

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BUSY_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BUSY_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

bool on = false;

void busy_task(__unused void *params) {
    sleep_ms(100);

    printf("Entering busy task\n");

    while(1) {
        uint32_t k;
        for (int i = 0; i < 30; i++) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
            asm ("");
        }
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        on = !on;
    }
}

int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;

    hard_assert(cyw43_arch_init() == PICO_OK);

    sleep_ms(100);

    printf("Entering Task\n");

    xTaskCreate(busy_task, "BusyThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
