all: dir.o
	gcc dir.o

dir.o: dir.c
	gcc -c dir.c

clean:
	rm -f *.o *~ a.out

run: all
	./a.out
