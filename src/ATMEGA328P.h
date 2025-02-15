#ifndef ATMEGA328P_H
#define ATMEGA328P_H

#define MCUCR ((unsigned char*)0x55)
#define PORTB ((unsigned char*)0x25)
#define DDRB ((unsigned char*)0x24)
#define PINB ((unsigned char*)0x23)
#define PORTC ((unsigned char*)0x28)
#define DDRC ((unsigned char*)0x27)
#define PINC ((unsigned char*)0x26)
#define PORTD ((unsigned char*)0x2B)
#define DDRD ((unsigned char*)0x2A)
#define PIND ((unsigned char*)0x29)

#define TCCR0A ((unsigned char*)0x44)
#define TCCR0B ((unsigned char*)0x45)

#define TCNT0 ((unsigned char*)0x46)

#define IVCE (1 << 0)
#define IVSEL (1 << 1)
#define PUD (1 << 4)
#define BODSE (1 << 5)
#define BODS (1 << 6)

#define PB0 (1 << 0)
#define PB1 (1 << 1)
#define PB2 (1 << 2)
#define PB3 (1 << 3)
#define PB4 (1 << 4)
#define PB5 (1 << 5)
#define PB6 (1 << 6)
#define PB7 (1 << 7)

#define DDB0 (1 << 0)
#define DDB1 (1 << 1)
#define DDB2 (1 << 2)
#define DDB3 (1 << 3)
#define DDB4 (1 << 4)
#define DDB5 (1 << 5)
#define DDB6 (1 << 6)
#define DDB7 (1 << 7)

#define PC0 (1 << 0)
#define PC1 (1 << 1)
#define PC2 (1 << 2)
#define PC3 (1 << 3)
#define PC4 (1 << 4)
#define PC5 (1 << 5)
#define PC6 (1 << 6)

#define DDC0 (1 << 0)
#define DDC1 (1 << 1)
#define DDC2 (1 << 2)
#define DDC3 (1 << 3)
#define DDC4 (1 << 4)
#define DDC5 (1 << 5)
#define DDC6 (1 << 6)

#define PD0 (1 << 0)
#define PD1 (1 << 1)
#define PD2 (1 << 2)
#define PD3 (1 << 3)
#define PD4 (1 << 4)
#define PD5 (1 << 5)
#define PD6 (1 << 6)
#define PD7 (1 << 7)

#define DDD0 (1 << 0)
#define DDD1 (1 << 1)
#define DDD2 (1 << 2)
#define DDD3 (1 << 3)
#define DDD4 (1 << 4)
#define DDD5 (1 << 5)
#define DDD6 (1 << 6)
#define DDD7 (1 << 7)

void toggle_pin(unsigned char*, unsigned char);
void set_pin(unsigned char*, unsigned char);
void unset_pin(unsigned char*, unsigned char);
void write_to_port(unsigned char*, unsigned char);
char get_pin(unsigned char*, unsigned char);

#endif // !ATMEGA328P_H
