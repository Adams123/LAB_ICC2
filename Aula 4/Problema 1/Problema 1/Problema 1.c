#include <stdio.h>
#include <stdlib.h>

void verifica(int *largada, int *chegada, int i, int j, int *cont)
{
    if(i==j) return;
    *cont+=j-i;
//    printf("Incrementou cont %d\n", *cont);
    int k;
    for(k=j;k>=i;k--)
        largada[k]=largada[k-1];
    largada[i]=chegada[i];
}

void printvet(int *v, int N)
{
    int i;
    for(i=0; i<N; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int bubble(int *largada, int *chegada, int N)
{
    int i, j, cont=0, k;
    for(i=0; i<N; i++)
        for(j=i; j<N; j++)
        {
            if(largada[j]==chegada[i]){
                verifica(largada,chegada,i,j,&cont);
                break;
            }
        }
//    printf("Cont %d\n\n", cont);
    return cont;
}

int main()
{

    int N, *largada, *cheg, i;
    while(scanf("%d", &N) != EOF)
    {
        largada = (int*)malloc(sizeof(int)*N);
        cheg = (int*)malloc(sizeof(int)*N);

        for(i=0; i<N; i++)
            scanf("%d", &largada[i]);
        for(i=0; i<N; i++)
            scanf("%d", &cheg[i]);

        printf("%d\n",bubble(largada, cheg, N));

//        printf("Final:\n");
//        printvet(largada,N);
//        printvet(cheg,N);
//        printf("\n");

        free(largada);
        free(cheg);

    }
    return 0;
}
