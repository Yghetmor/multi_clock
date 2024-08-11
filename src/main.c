#include "ATMEGA328P.h"
#include "LCD.h"

int main() 
{
    set_pin(DDRB, 0xFF);
    set_pin(DDRD, PD5 | PD6 | PD7);
    LCD_init();

    const char *msg = "Hello there !";
    LCD_print((const unsigned char*)msg);

    while (1)
    {

    }

    return 0;
}
