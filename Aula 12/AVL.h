#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node*  left;
    struct node*  right;
    int height;
} node;

void print();
void dispose(node* t);
node* busca( int e, node *t );
node* find_min( node *t );
node* find_max( node *t );
node* insere( int data, node *t );
void display_avl(node* t);
int get( node* n );
