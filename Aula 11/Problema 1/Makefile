all: clean ArithTree.o main.o compile

compile:
	@gcc ArithTree.o main.o -o Problema1 -g

main.o:
	@gcc -c main.c -g

ArithTree.o:
	@gcc -c ArithTree.c -g

clean:
	@-rm *.o

run:
	@./Problema1

zip:
	zip -r Problema1 *.c *.h Makefile
