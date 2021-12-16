OUTPUT = stringProg
CC = gcc
CFLAGS = -Wall -g
OBJ = functionA.o functionB.o functionC.o


all: output functions

main.o: main.c string_Prog.h
	$(CC) -c $(CFLAGS) main.c

functionA.o: functionA.c string_Prog.h
	$(CC) -c $(CFLAGS) functionA.c

functionB.o: functionB.c string_Prog.h
	$(CC) -c $(CFLAGS) functionB.c

functionC.o: functionC.c string_Prog.h
	$(CC) -c $(CFLAGS) functionC.c

functions: libfunctions.so

libfunctions.so: $(OBJ)
	$(CC) -shared -fPIC -o libfunctions.so $(OBJ)

output: main.o libfunctions.so
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o ./libfunctions.so

.PHONY: all clean functions output

clean:
	rm -f *.o *.so $(OUTPUT)
