OUTPUT = out
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o OutFunctions.o


.PHONY: all clean

all: output

main.o: main.c OutFunctions.h
    $(CC) -c $(CFLAGS) main.c

OutFunctions.o: OutFunctions.c OutFunctions.h
    $(CC) -c $(CFLAGS) OutFunctions.c

output: $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

clean:
    rm -f *.o *.txt $(OUTPUT)