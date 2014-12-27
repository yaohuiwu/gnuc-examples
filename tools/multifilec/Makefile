main: main.o calculator.o
	gcc main.o calculator.o -o main
calculator.o: calculator.c calculator.h
	gcc -c calculator.c
main.o: main.c calculator.h
	gcc -c main.c
clean: 
	rm -rf *.o main
