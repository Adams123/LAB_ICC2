all: BSTree.o main.o compile

compile:
	@gcc BSTree.o main.o -o Problema1 -g

main.o:
	@gcc -c main.c -g

BSTree.o:
	@gcc -c BSTree.c -g

clean:
	@-rm *.o

run:
	@./Problema1

zip:
	zip -r Problema1 *.c *.h Makefile
