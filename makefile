CC=avr-gcc
OBJ = avr-objcopy
DUMP = avr-objdump
SIZE = avr-size
MCU = -mmcu=atmega328
SDIR=./src
DEPS = $(SDIR)/ATMEGA328P.c  $(SDIR)/LCD.c

all : kernel7.hex

kernel7.hex : a.out
	$(OBJ) -O ihex a.out kernel7.hex

a.out : $(SDIR)/main.c $(DEPS)
	$(CC) $(MCU) -Os $(SDIR)/main.c $(DEPS)

%.o : %.c $(DEPS)
	$(CC) -mmcu=atmega328 -c -Os $@ @$< $(CFLAGS)

# clean :
# 	rm $(SDIR)($(*.out) $(*.hex) $(*.o) $(*.gch)) main.txt

size :
	$(SIZE) -C $(MCU)p main.out

dump :
	$(DUMP) -d main.out > main.txt

dump-all :
	$(DUMP) -j .data .text -D > main.txt







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
