CC = gcc
CFLAGES = -I.
fprintf:fprintf.o
	$(CC) -o  fprintf -g fprintf.o $(CFLAGES)


clean:
	rm -rf fprintf fprintf.o