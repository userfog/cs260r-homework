CC=clang
CFLAGS=-Wall -O2
VERSION=sat_ops 

all: $(VERSION)

$(VERSION): main.o sat_ops.o 
	$(CC) $(FLAGS) -o $(VERSION) main.o $(addsuffix .o, $(VERSION)) $(LIBS)

main.o: main.c sat_ops.h
	$(CC) $(CFLAGS) -c main.c $(LIBS)

sat_ops.o: sat_ops.h
	$(CC) $(CFLAGS) -c  $(addsuffix .c, $(VERSION)) $(LIBS)

clean:
	rm -rf *.o $(VERSION)
