#include "avl.h"

void clear(node* t)
{
    if( t != NULL )
    {
        clear( t->left );
        clear( t->right );
        free( t );
    }
}


node* busca(int target, node* t )
{
    if( t == NULL )
        return NULL;
    if( target < t->data )
        return busca( target, t->left );
    else if( target > t->data )
        return busca( target, t->right );
    else
        return t;
}


static int height( node* no )
{
    if( no == NULL )
        return -1;
    else
        return no->height;
}

static int max( int l, int r)
{
    return l > r ? l: r;
}


static node* roda_esquerda( node* n2 )
{
    node* n1 = NULL;

    n1 = n2->left;
    n2->left = n1->right;
    n1->right = n2;

    n2->height = max( height( n2->left ), height( n2->right ) ) + 1;
    n1->height = max( height( n1->left ), n2->height ) + 1;
    return n1; /* new root */
}


static node* roda_direita( node* n1 )
{
    node* n2;

    n2 = n1->right;
    n1->right = n2->left;
    n2->left = n1;

    n1->height = max( height( n1->left ), height( n1->right ) ) + 1;
    n2->height = max( height( n2->right ), n1->height ) + 1;

    return n2;
}

static node* roda_esquerda_dois( node* n3 )
{
    n3->left = roda_direita( n3->left );

    return roda_esquerda( n3 );
}



static node* roda_direita_dois( node* n1 )
{
    n1->right = roda_esquerda( n1->right );

    return roda_direita( n1 );
}

node* insere(int target, node* t )
{
    if( t == NULL )
    {
        t = (node*)malloc(sizeof(node));
            t->data = target;
            t->height = 0;
            t->left = t->right = NULL;
    }
    else if( target < t->data )
    {
        t->left = insere( target, t->left );
        if( height( t->left ) - height( t->right ) == 2 ){
            if( target < t->left->data ){
                t = roda_esquerda( t );
            }
            else {
                t = roda_esquerda_dois( t );
            }
        }
    }
    else if( target > t->data )
    {
        t->right = insere( target, t->right );
        if( height( t->right ) - height( t->left ) == 2 ){
            if( target > t->right->data ){
                t = roda_direita( t );
            }
            else{
                t = roda_direita_dois( t );
            }
        }
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;
    return t;
}


int get(node* n)
{
    return n->data;
}

void display_avl(node* t)
{
    if (t == NULL)
        return;
    printf("%d",t->data);

    if(t->left != NULL)
        printf("(L:%d)",t->left->data);
    if(t->right != NULL)
        printf("(R:%d)",t->right->data);
    printf("\n");

    display_avl(t->left);
    display_avl(t->right);
}
