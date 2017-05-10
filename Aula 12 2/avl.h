#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node*  left;
    struct node*  right;
    int height;
} node;

void clear(node* t);
node* busca( int e, node *t );
node* insere( int data, node *t );
void display_avl(node* t);
int get( node* n );
