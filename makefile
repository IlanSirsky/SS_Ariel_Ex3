OUTPUT = stringProg
CC = gcc
AR = ar
CFLAGS = -Wall -g
OBJ = functionA.o functionB.o functionC.o


all: stringProg functions

main.o: main.c string_Prog.h
	$(CC) -c $(CFLAGS) main.c

functionA.o: functionA.c string_Prog.h
	$(CC) -c $(CFLAGS) functionA.c

functionB.o: functionB.c string_Prog.h
	$(CC) -c $(CFLAGS) functionB.c

functionC.o: functionC.c string_Prog.h
	$(CC) -c $(CFLAGS) functionC.c

functions: libfunctions.a

libfunctions.a: $(OBJ)
	$(AR) -rcs libfunctions.a $(OBJ)

stringProg: main.o libfunctions.a
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o libfunctions.a

.PHONY: all clean functions output

clean:
	rm -f *.o *.a $(OUTPUT)
