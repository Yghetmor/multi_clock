#include "ATMEGA328P.h"

void toggle_pin(unsigned char* addr, unsigned char pin)
{
    *addr ^= pin;
}
