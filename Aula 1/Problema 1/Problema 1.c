#include <stdio.h>
#include <stdlib.h>
int main()
{
    int left=-1, right=-1, count=0;
    while(1)
    {
        scanf("%d", &left);
        scanf("%d", &right);
        if(left==0 && right==0) break;
        printf("%d\n", left+right);
    }
    return 0;
}
