#include "LCD.h"
#include "ATMEGA328P.h"

#define DATA PORTB
#define REG_OP PORTD

#define D0 (1<<0)
#define D1 (1<<1)
#define D2 (1<<2)
#define D3 (1<<3)
#define D4 (1<<4)
#define D5 (1<<5)
#define D6 (1<<6)
#define D7 (1<<7)

#define REG_SEL     (1<<5)
#define RW          (1<<6)
#define ENABL       (1<<7)

#define CLEAR_DISP  (0x01)
#define RET_HOME    (0x02)
#define DISP_ONOFF  (0x0C)

void write_data(unsigned char);
void send_instruction(unsigned char);
void send_data(unsigned char);

void LCD_init()
{
    send_instruction(CLEAR_DISP);
    send_instruction(RET_HOME);
    send_instruction(DISP_ONOFF);
}

void LCD_print(const unsigned char *msg)
{
    while(*msg != '\0')
    {
        send_data(*msg);
        msg++;
    }
}

void write_data(unsigned char val)
{
    write_to_port(DATA, val);
}

void send_instruction(unsigned char inst)
{
    unset_pin(REG_OP, REG_SEL | RW);
    // wait ?
    set_pin(REG_OP, ENABL);
    // wait ?
    write_data(inst);
    // wait ?
    unset_pin(REG_OP, ENABL);
}

void send_data(unsigned char val)
{
    set_pin(REG_OP, REG_SEL);
    unset_pin(REG_OP, RW);
    // wait ?
    set_pin(REG_OP, ENABL);
    // wait ?
    write_data(val);
    // wait ?
    unset_pin(REG_OP, ENABL);
}
