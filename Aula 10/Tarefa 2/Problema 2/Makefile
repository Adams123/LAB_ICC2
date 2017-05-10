all: BSTree.o NodeQueue.o main.o compile

compile:
	@gcc BSTree.o NodeQueue.o main.o -o Problema2 -g

main.o:
	@gcc -c main.c -g

BSTree.o:
	@gcc -c BSTree.c -g

NodeQueue.o:
	@gcc -c NodeQueue.c -g
	
clean:
	@-rm *.o

run:
	@./Problema2

zip:
	zip -r Problema2 *.c *.h Makefile
