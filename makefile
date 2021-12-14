OUTPUT = stringProg
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o string_Prog.o


.PHONY: all clean

all: output

main.o: main.c string_Prog.h
	$(CC) -c $(CFLAGS) main.c

string_Prog.o: string_Prog.c string_Prog.h
	$(CC) -c $(CFLAGS) string_Prog.c

output: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

clean:
	rm -f *.o *.txt $(OUTPUT)
