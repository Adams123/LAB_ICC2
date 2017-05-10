#include <stdio.h>
#include <stdlib.h>

typedef struct pnt
{
    int x, y;
} ponto;


typedef struct vrtc vertice;
struct vrtc
{
    ponto p;
    vertice* prox;
};

typedef struct fig
{
    int N;
    int Dy, Dx;
    vertice* p_inicio;
} figura;

int main()
{

    ponto vetor[10];

    int N, dx, dy,i;
    while(1)
    {

        scanf("%d",&N); //leitura de quantos vértices
        if(N >=10 || N<=0)
        {
            return 0;
        }

        for(i=0; i<N; i++)
        {
            scanf("%d",&vetor[i].x); //leitura dos N vertices
            scanf("%d",&vetor[i].y);
        }
        scanf("%d %d", &dx, &dy);
        for(i=0; i<N; i++)
        {
            vetor[i].x += dx;
            vetor[i].y += dy;
            printf("%d %d ", vetor[i].x, vetor[i].y);
        }
    }
    return 0;
}
