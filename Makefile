counter: main.o inputreader.o cardpicker.o counter.h
	gcc main.o inputreader.o cardpicker.o -o counter

main.o: main.c counter.h
	gcc -c main.c -o main.o

inputreader.o: inputreader.c counter.h
	gcc -c inputreader.c -o inputreader.o

cardpicker.o: cardpicker.c counter.h
	gcc -c cardpicker.c -o cardpicker.o