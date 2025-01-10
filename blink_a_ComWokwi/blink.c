
#include <stdbool.h>
#include "pico/stdlib.h"

#define led_pin_red 13
float ponto = 200;
float traco = 800;
float intervalo = 125;
float intervalo_letra = 250;
float intervalo_ciclo = 3000;


void emitir_ponto() {
    gpio_put(led_pin_red, true);
    sleep_ms(ponto);
    gpio_put(led_pin_red, false);
}

void emitir_traco() {
    gpio_put(led_pin_red, true);
    sleep_ms(traco);
    gpio_put(led_pin_red, false);
}

void enviar_sos() {
    // Enviar "S" (três pontos)
    for (int i = 0; i < 3; i++) {
        emitir_ponto();
        if (i < 2) sleep_ms(ponto); // Intervalo entre pontos
    }
    sleep_ms(intervalo_letra); // Intervalo entre letras

    // Enviar "O" (três traços)
    for (int i = 0; i < 3; i++) {
        emitir_traco();
        if (i < 2) sleep_ms(traco); // Intervalo entre traços
    }
    sleep_ms(intervalo_letra); // Intervalo entre letras

    // Enviar "S" novamente (três pontos)
    for (int i = 0; i < 3; i++) {
        emitir_ponto();
        if (i < 2) sleep_ms(intervalo); // Intervalo entre pontos
    }

    // Pausar antes de reiniciar o ciclo
    sleep_ms(intervalo_ciclo);
}

int main() {
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
 
     while (true) {
       enviar_sos();
    }
    return 0;
}