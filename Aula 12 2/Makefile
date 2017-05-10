all: avl.o main.o compile

compile:
	@gcc avl.o main.o -o Problema1 -g

main.o:
	@gcc -c main.c -g

avl.o:
	@gcc -c avl.c -g

	
clean:
	@-rm *.o

run:
	@./Problema1

zip:
	zip -r Problema1 *.c *.h Makefile
