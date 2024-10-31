#define CHIP_6713

#include <stdio.h>
#include <stdlib.h>
#include "dsk6713.h"
#include "dsk6713_led.h"

void main(void)
{

    DSK6713_init();

    DSK6713_LED_init();

    int ledIndex = 0;

    while(1)
    {
        DSK6713_LED_on(ledIndex);

        DSK6713_waitusec(500000);

        DSK6713_LED_off(ledIndex);

        DSK6713_waitusec(500000);    }
}
