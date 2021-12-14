OUTPUT = stringProg
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o 


.PHONY: all clean

all: output

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

output: $(OBJ)
	$(CC) $^ -o $(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)
