#include "AVL.h"

int main()
{
    node *t;

    t = NULL;
    print();
    t = insere(10,t);

    display_avl(t);

    dispose(t);

    return 0;
}
