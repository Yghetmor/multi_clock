#define F_CPU 1000000UL
#include <util/delay.h>
#include "ATMEGA328P.h"
#include "LCD.h"

int main() 
{
    set_pin(DDRB, 0xFF);
    set_pin(DDRD, PD5 | PD6 | PD7);
    LCD_init();

    const char *msg = "Bebilii";
    _delay_ms(1);
    LCD_print((const unsigned char*)msg);

    while (1)
    {

    }

    return 0;
}
