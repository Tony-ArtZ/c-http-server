CC=gcc
CFLAGS=-Wall

all: server

server: server.o handler.o mime.o
	$(CC) $(CFLAGS) -o server server.o handler.o mime.o

server.o: server.c server.h
	$(CC) $(CFLAGS) -c server.c

handler.o: handler.c server.h
	$(CC) $(CFLAGS) -c handler.c

mime.o: mime.c server.h
	$(CC) $(CFLAGS) -c mime.c

clean:
	rm -f *.o server
