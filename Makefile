counter: main.o inputreader.o counter.h
	gcc main.o inputreader.o -o counter

main.o: main.c counter.h
	gcc -c main.c -o main.o

inputreader.o: inputreader.c counter.h
	gcc -c inputreader.c -o inputreader.o