CC=avr-gcc
OBJ = avr-objcopy
DUMP = avr-objdump
SIZE = avr-size
MCU = atmega328
FLASHER = avrdude
PROGRAMMER = usbasp
KERNEL = kernel7.hex
SDIR=./src
DEPS = $(SDIR)/ATMEGA328P.c  $(SDIR)/LCD.c

flash : all
	$(FLASHER) -v -B4 -F -p $(MCU) -c $(PROGRAMMER) -U flash:w:$(KERNEL)

all : $(KERNEL)

$(KERNEL) : a.out
	$(OBJ) -O ihex a.out $(KERNEL)

a.out : $(SDIR)/main.c $(DEPS)
	$(CC) -mmcu=$(MCU) -Os $(SDIR)/main.c $(DEPS)

%.o : %.c $(DEPS)
	$(CC) -mmcu=$(MCU) -c -Os $@ @$< $(CFLAGS)

clean :
	rm $($(SDIR)/*.gch) $(KERNEL) a.out main.txt

size :
	$(SIZE) -C --mcu=$(MCU)p a.out

dump :
	$(DUMP) -d a.out > main.txt

dump-all :
	$(DUMP) -j .data -j .text -D a.out > main.txt







# %.o : %.c $(DEPS)
# 	$(CC) -mmcu=atmega328 -c -Os $@ @$< $(CFLAGS)
#
# all: main
# 	$(OBJ) -O ihex a.out kernel7.hex
# 	rm a.out
#
# main: $(SDIR)/main.c $(DEPS)
# 	$(CC) -mmcu=atmega328 -Os src/main.c src/ATMEGA328P.c src/LCD.c
#
# clean : 
# 	if [ -e kernel7.hex ];
# 	then
# 		rm kernel7.hex
# 	fi
