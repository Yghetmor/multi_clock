#define F_CPU 1000000UL
#include <util/delay.h>
#include "dht.h"
#include "ATMEGA328P.h"

#define TIMEOUT 10000

#define PORT            PORTC
#define PORT_DIRECTION  DDRC
#define PIN             PC5
#define DIRECTION_PIN   DDC5
#define TIMER           TCNT0

int read_temp_hum(union dht11 *output) 
{
    for (int i = 0; i < 5; i++)
    {
        output->bytes[i] = 0;
    }

    set_pin(PORT_DIRECTION, DIRECTION_PIN);
    unset_pin(PORT, PIN);
    _delay_ms(20);
    set_pin(PORT, PIN);
    _delay_us(40);
    unset_pin(PORT_DIRECTION, DIRECTION_PIN);

    int loop_cnt = TIMEOUT;
    while(get_pin(PORT, PIN) != PIN)
        if (loop_cnt-- == 0) return -1;

    loop_cnt = TIMEOUT;
    while(get_pin(PORT, PIN) == PIN)
        if (loop_cnt-- == 0) return -1;

    char bit_cnt = 7;
    char idx = 0;

    for (int i = 0; i < 40; i++)
    {

        loop_cnt = TIMEOUT;
        while(get_pin(PORT, PIN) != PIN)
            if (loop_cnt-- == 0) return -1;

        *TIMER = 0x0000;

        loop_cnt = TIMEOUT;
        while(get_pin(PORT, PIN) == PIN)
            if (loop_cnt-- == 0) return -1;

        if (*TIMER > 40)
        {
            set_pin(output->bytes + idx, 1 << bit_cnt);
        }

        if (bit_cnt == 0)
        {
            idx++;
            bit_cnt = 7;
        }
        else
        {
            bit_cnt--;
        }
    }
}
