#include "ATMEGA328P.h"

void toggle_pin(unsigned char* port, unsigned char pin)
{
    *port ^= pin;
}

void write_to_port(unsigned char * port, unsigned char val)
{
    *port = val;
}

void set_pin(unsigned char * port, unsigned char pin)
{
    *port |= pin;
}

void unset_pin(unsigned char * port, unsigned char pin)
{
    *port &= (~pin);
}
