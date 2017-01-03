CC = /usr/bin/gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror
LDFLAGS = -lpthread

OBJFILES = client.o parameter.o connectServer.o performConnection.o responseHandler.o processRequest.o config.o sharedMemory.o think.o print.o

bashni: play

client.o: client.c client.h
	$(CC) $(CFLAGS) -c client.c

parameter.o: parameter.c parameter.h
	$(CC) $(CFLAGS) -c parameter.c

connectServer.o: connectServer.c connectServer.h
	$(CC) $(CFLAGS) -c connectServer.c

performConnection.o: performConnection.c performConnection.h
	$(CC) $(CFLAGS) -c performConnection.c

responseHandler.o: responseHandler.c responseHandler.h
	$(CC) $(CFLAGS) -c responseHandler.c

processRequest.o: processRequest.c processRequest.h
	$(CC) $(CFLAGS) -c processRequest.c

config.o: config.c config.h
	$(CC) $(CFLAGS) -c config.c

sharedMemory.o: sharedMemory.c sharedMemory.h
	$(CC) $(CFLAGS)	-c sharedMemory.c

think.o: think.c think.h
	$(CC) $(CFLAGS) -c think.c

print.o: print.c print.h
	$(CC) $(CFLAGS) -c print.c

client: $(OBJFILES)
	$(CC) $(CFLAGS) -o client $(OBJFILES)

play: ./client
	./client $(GAME_ID) $(PLAYER) $(CONF_FL)

clean:
	rm -f $(OBJFILES) play
