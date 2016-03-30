CC=gcc
OBJS=
CFLAGS=-Wall -Iinclude/
LDFLAGS=

test : main.o $(OBJS)
	$(CC) -o test.out $^ $(CFLAGS) -Llib -lcunit $(LDFLAGS)

.PHONY: clean
clean: 
	rm -f *.o 
