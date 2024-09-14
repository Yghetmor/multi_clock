#define F_CPU 1000000UL
#include <util/delay.h>
#include "LCD.h"
#include "ATMEGA328P.h"

#define DATA PORTB
#define REG_OP PORTD

#define D0 (1<<4)
#define D1 (1<<5)
#define D2 (1<<6)
#define D3 (1<<7)

#define REG_SEL     (1<<5)
#define RW          (1<<6)
#define ENABL       (1<<7)

#define CLEAR_DISP  (0x01)
#define RET_HOME    (0x02)
#define ENTRY_MODE  (0x06)
#define DISP_ONOFF  (0x0C)

void send_4bit_instruction(unsigned char);
void send_4bit_data(unsigned char);
void send_4bit_init();

void LCD_init()
{
    _delay_ms(2000);
    write_to_port(DATA, 0);
    send_4bit_init();
    send_4bit_instruction(CLEAR_DISP);
    send_4bit_instruction(RET_HOME);
    send_4bit_instruction(ENTRY_MODE);
    send_4bit_instruction(DISP_ONOFF);
}

void LCD_print(const unsigned char *msg)
{
    send_4bit_instruction(CLEAR_DISP);
    send_4bit_instruction(RET_HOME);
    send_4bit_instruction(ENTRY_MODE);
    const unsigned char *ptr = msg;
    while(*ptr != '\0')
    {
        send_4bit_data(*ptr);
        ptr++;
    }
}

void send_4bit_init() 
{
    unset_pin(REG_OP, REG_SEL | RW);
    _delay_us(100);
    write_to_port(DATA, 0x20);
    // wait ?
    _delay_us(100);
    set_pin(REG_OP, ENABL);
    _delay_us(100);
    unset_pin(REG_OP, ENABL);
    _delay_us(100);
}

void send_4bit_instruction(unsigned char inst)
{
    unset_pin(REG_OP, REG_SEL | RW);
    _delay_us(100);
    write_to_port(DATA, (inst & 0xF0) >> 4);
    // wait ?
    _delay_us(100);
    set_pin(REG_OP, ENABL);
    _delay_us(100);
    unset_pin(REG_OP, ENABL);

    _delay_us(100);
    write_to_port(DATA, inst & 0x0F);
    // wait ?
    _delay_ms(1);
    set_pin(REG_OP, ENABL);
    _delay_us(100);
    unset_pin(REG_OP, ENABL);
    _delay_us(100);
}

void send_4bit_data(unsigned char val)
{
    set_pin(REG_OP, REG_SEL);
    unset_pin(REG_OP, RW);
    // wait ?
    _delay_us(100);
    write_to_port(DATA, (val & 0xF0) >> 4);
    // wait ?
    _delay_us(100);
    set_pin(REG_OP, ENABL);
    // wait ?
    _delay_us(100);
    unset_pin(REG_OP, ENABL);

    _delay_us(100);
    write_to_port(DATA, val & 0x0F);
    // wait ?
    _delay_us(100);
    set_pin(REG_OP, ENABL);
    // wait ?
    _delay_us(100);
    unset_pin(REG_OP, ENABL);
    _delay_us(100);
}
