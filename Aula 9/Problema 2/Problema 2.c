#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len 101
int heapsize;


typedef struct {
	char **Palavras;
	int tam;
	int (*compare)(char *, char *);
}HEAP;

int heap_compare(char *p1, char *p2)
{
	return strcmp(p1, p2);
}

void desaloca(HEAP *heap){
	int i;
	for(i=0;i<heapsize;i++)
		free(heap->Palavras[i]);
	free(heap->Palavras);
}

void add

int main()
{
	HEAP *heap = (HEAP*)malloc(sizeof(HEAP));
	scanf("%d", &heapsize);

	int i;
	heap->Palavras=(char**)malloc(sizeof(char)*heapsize);
	for(i=0;i<heapsize;i++)
		heap->Palavras[i]=(char*)malloc(sizeof(char)*len);
	desaloca(heap);
	free(heap);
	return 0;
}
