#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Ponto{
    int x;
    int y;
}ponto;

int busca(int *v, ponto key, int tam)
{
    int mid, left = 0;
    while(left <= tam){
        mid = left + (tam-left)/2;
        if(distancia(key.x, key.y, v[mid])) left=mid+1;
        else if(distancia(key.x, key.y, v[mid])) tam=mid;
        else return mid;
    }
    return -1;
}

int distancia(int x, int y, int r)
{
    int result = pow(x,2) + pow(y,2);
    if(result < pow(r,2)) return 1;
    else if(result > pow(r,2)) return 0;
    else return -1;
}

int main()
{
    int C, N, *vet, i, j;
    long int pontos =0;
    ponto *jogadas;
    while(scanf("%d %d", &C, &N) != EOF)
    {
        vet = (int*)malloc(sizeof(int)*C);
        jogadas = (ponto*)malloc(sizeof(ponto));
        for(i=0;i<C;i++){
            scanf("%d", &vet[i]);
        }
        for(i=0;i<N;i++)
        {
            scanf("%d %d", &jogadas[0].x,&jogadas[0].y);
            int pos = busca(vet,jogadas[0],C);
            printf("Achou em %d\n", pos);
            for(j=0;j<C;j++){
                if(distancia(jogadas[0].x, jogadas[0].y, vet[j]))
                    pontos++;
            }
        }
        printf("%ld\n", pontos);
        pontos =0;
    }
    free(vet);
    free(jogadas);
    return 0;
}