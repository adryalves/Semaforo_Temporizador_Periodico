#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_VERMELHO 13 // GPIO do LED vermelho
#define LED_AMARELO 12  // GPIO do LED amarelo
#define LED_VERDE 11    // GPIO do LED verde

volatile int estado = 0; // Estado do semáforo

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t)
{
    // Alterna entre os estados do semáforo
    switch (estado)
    {
    case 0: // Vermelho -> Amarelo
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
        estado = 1;
        break;
    case 1: // Amarelo -> Verde
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 1);
        estado = 2;
        break;
    case 2: // Verde -> Vermelho
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
        estado = 0;
        break;
    }
    return true; // Continua chamando o temporizador
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial

    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_put(LED_VERMELHO, 1); // Inicia com o LED vermelho ligado
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer); // Temporizador de 3 segundos

    while (true)
    {
        printf("Semáforo operando...\n"); // Mensagem na serial a cada 1 segundo
        sleep_ms(1000);
    }
}
