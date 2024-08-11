CC=avr-gcc
SDIR=./src
DEPS = $(SDIR)/ATMEGA328P.h  $(SDIR)/LCD.h

%.o : %.c $(DEPS)
	$(CC) -mmcu=atmega328 -c -Os $@ @$< $(CFLAGS)

all: main
	avr-objcopy -O ihex a.out kernel7.hex
	rm a.out

main: $(SDIR)/main.c $(DEPS)
	$(CC) -mmcu=atmega328 -Os src/main.c src/ATMEGA328P.c src/LCD.c

clean : 
	if [ -e kernel7.hex ];
	then
		rm kernel7.hex
	fi
	if [ -e a.out ];
	then
		rm a.out
	fi
