# Makefile comments……
PROGRAMS = driver
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o
# C compilations
priorityQueueInt.o: priorityQueueInt.c priorityQueueInt.h
	$(CC) $(CFLAGS) -c priorityQueueInt.c
driver.o: driver.c priorityQueueInt.h
	$(CC) $(CFLAGS) -c driver.c
# Executable programs
driver: priorityQueueInt.o driver.o
	$(CC) $(CFLAGS) -o driver priorityQueueInt.o driver.o

