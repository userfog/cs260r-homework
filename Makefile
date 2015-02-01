CC=clang
CFLAGS=-Wall -O3
LIBS=-lm

all: sat_ops

sat_ops: main.o sat_ops.o 
	$(CC) $(FLAGS) -o sat_ops main.o sat_ops.o $(LIBS)

main.o: main.c sat_ops.h
	$(CC) $(CFLAGS) -c main.c $(LIBS)

sat_ops.o: sat_ops.c sat_ops.h
	$(CC) $(CFLAGS) -c sat_ops.c $(LIBS)


clean:
	rm -rf *.o sat_ops
