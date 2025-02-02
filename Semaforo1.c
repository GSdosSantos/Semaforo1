#include <stdio.h>
#include "pico/stdlib.h"

#define verm 11
#define amar 12
#define verd 13
int estado = 0;

char infoestado[3][6] = {"verm", "amar", "verd"};
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado){
        case 0: gpio_put(verm,true);gpio_put(amar,false);gpio_put(verd,false);break;
        case 1: gpio_put(verm,false);gpio_put(amar,true);gpio_put(verd,false);break;
        case 2: gpio_put(verm,false);gpio_put(amar,false);gpio_put(verd,true);break;
    }
    estado++;
    if(estado==3){
        estado=0;
    }
    return true;
}

int main()
{
    
    stdio_init_all();
    gpio_init(verm);
    gpio_set_dir(verm,GPIO_OUT);
    gpio_init(amar);
    gpio_set_dir(amar,GPIO_OUT);
    gpio_init(verd);
    gpio_set_dir(verd,GPIO_OUT);
    repeating_timer_t timer;
    add_repeating_timer_ms(3000, repeating_timer_callback,NULL, &timer);
    
    while (true) {
         printf("Estado %d: %s\n", estado, infoestado[estado]);
        sleep_ms(1000);
    }
}
