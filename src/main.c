#define F_CPU 1000000UL
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "ATMEGA328P.h"
#include "LCD.h"
#include "dht.h"

int main() 
{
    set_pin(DDRB, 0xFF);
    set_pin(DDRD, PD5 | PD6 | PD7);
    set_pin(DDRC, PC5);

    write_to_port(TCCR0A, 0x00);
    write_to_port(TCCR0B, 0x01);

    LCD_init();

    while (1)
    {
        union dht11 measures;
        read_temp_hum(&measures);

        char temp_output[17];
        char hum_output[17];

        char temperature[3];
        char humidity[3];
        itoa((int)measures.data.temp_integral, temperature, 10);
        itoa((int)measures.data.hum_integral, humidity, 10);

        char *temp_txt = "Temperature ";
        char *hum_txt = "Humidity ";
        char temp_suffix[3] = {0b11011111, 'C', '\0'};
        char hum_suffix[2] = {'%', '\0'};

        strcat(temp_output, temp_txt);
        strcat(temp_output, temperature);
        strcat(temp_output, temp_suffix);

        strcat(hum_output, hum_txt);
        strcat(hum_output, humidity);
        strcat(hum_output, hum_suffix);

        char output[33];
        memset(output, 0, 33);
        strcpy(output, temp_output);
        strcat(output, hum_output);

        LCD_print(output);

        _delay_ms(2500);
    }

    return 0;
}
