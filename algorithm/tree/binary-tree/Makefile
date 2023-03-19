CC	= g++
CFLAGS	= -Wall --pedantic-error
PROGRAM	= main
DEBUG	= debug

$(PROGRAM): main.o
	$(CC) $(CFLAGS) -o main.out main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:; rm -rf *.o $(PROGRAM)

test:; ./main.out < test.txt

copy:; cat ./main.cpp | pbcopy 

debug: debug
	$(CC) $(CFLAGS) -g -o debug.out main.cpp
