OUTPUT = stringProg
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o functions.o


.PHONY: all clean

all: output

main.o: main.c string_Prog.h
	$(CC) -c $(CFLAGS) main.c

functions.o: functions.c string_Prog.h
	$(CC) -c $(CFLAGS) functions.c

output: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

clean:
	rm -f *.o *.txt $(OUTPUT)
