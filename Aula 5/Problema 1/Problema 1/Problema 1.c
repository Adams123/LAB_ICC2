#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int frequencia;
} character;

int compare(const void* a, const void* b)
{
    const character* l = (const character*) a;
    const character* r = (const character*) b;
    if (l->frequencia == r->frequencia)
        return (r->c - l->c);
    return (l->frequencia - r->frequencia);
}

int main(void)
{
    char entrada[2000];
    int primeiro = 1;
    while(!feof(stdin))
    {
        fgets(entrada,1000,stdin);
        int i, tam;
        character freqs[256] = {0, 0};
        for (i = 0, tam = strcspn(entrada, "\n"); i < tam; ++i)
        {
            freqs[entrada[i]].c = entrada[i];
            ++freqs[entrada[i]].frequencia;
        }
        qsort(freqs, 256, sizeof(character), compare);

        if (!primeiro) printf("\n");
        primeiro = 0;

        for (i = 0; i < 256; ++i)
        {
            if (freqs[i].c)
                printf("%d %d\n", freqs[i].c, freqs[i].frequencia);
        }
    }
    return 0;
}
