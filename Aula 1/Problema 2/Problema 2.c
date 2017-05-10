#include <stdio.h>
#include <stdlib.h>
int* carrega(int N)
{
    int *vet;
    vet = (int*)malloc(sizeof(int)*N);
    int i;
    for(i=0; i<N; i++)
        scanf("%d", &vet[i]);
    return vet;
}
short achou (int vetor[], int N, int v, int *pos)
{
    int i;
    for(i=0; i<N; i++)
        if(vetor[i]==v)
        {
            *pos = i;
            return 1;
        }
    return 0;
}
int main()
{
    int tam, *vet, v, pos;
    short result;
    while(1)
    {
        scanf("%d", &tam);
        if(tam == 0) return 0;
        vet = carrega(tam);
        scanf("%d", &v);
        result = achou(vet,tam,v,&pos);
        //printf("%d", pos);
        if(result) printf("S");
        else printf("N");
    }
}

