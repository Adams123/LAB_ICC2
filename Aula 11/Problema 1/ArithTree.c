#include "ArithTree.h"

int total_n = 0;

ArithTree *createArithTree()
{
    ArithTree *tree = (ArithTree*)malloc(sizeof(ArithTree));
    tree->root=NULL;
    return tree;
}

node *insereVal(node *root, double val)
{
    if(root==NULL)
    {
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->val= val;
        temp->flag=1;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(val>(root->val))
    {
        root->right = insereVal(root->right,val);
    }
    else if(val < (root->val))
    {
        root->left= insereVal(root->left,val);
    }
    return root;
}

node *insere(node *root, const char *equation)
{
    int n;
    double val;
    if(equation[total_n]=='\0')
        return NULL;
    if(root==NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->left = root->right = NULL;
    }

    if(equation[total_n]=='*' ||equation[total_n]=='-' ||equation[total_n]=='+' ||equation[total_n]=='/') //sinal
    {
        root->flag=0;
        switch(equation[total_n])
        {
        case '+':
            root->op = '+';
            break;
        case '-':
            root->op = '-';
            break;
        case '*':
            root->op = '*';
            break;
        case '/':
            root->op = '/';
            break;
        }
        root->left=root->right=NULL;
        root->val=0;
        total_n=total_n+2;
        if(equation[total_n]=='\0')
            return root;
        root->left = insere(root->left, equation);
        total_n=total_n+2;
        if(equation[total_n]=='\0')
            return root;
        root->right = insere(root->right, equation);
        return root;
    }
    else
    {
        sscanf(equation + total_n-1, "%*[^0123456789]%lf%n", &val, &n);
        printf("Inserindo valor %.2f\n", val);
        root = insereVal(root, val);
        total_n+=n;
        if(equation[total_n]=='\0')
            return root;
        return root;
    }

}

void buildArithTree(ArithTree *t, const char *equation)
{
    t->root=insere(t->root,equation);
}



void printInOrder(ArithTree *t)
{
    inorder(t->root);
}

void inorder(node *n)
{
    if(n!=NULL)
    {
        printf("(");
        inorder(n->left);
        if(!n->flag) printf(" %c ", n->op);
        else printf("%.2f", n->val);
        inorder(n->right);
        printf(")");
    }
}

double solveArithTree(ArithTree *t)
{
    return resolve(t->root);
}

double resolve(node *no)
{
    if(!no->flag)
    {
        switch(no->op)
        {
        case '+':
            return resolve(no->left) + resolve(no->right);
            break;
        case '-':
            return resolve(no->left) - resolve(no->right);
            break;
        case '*':
            return resolve(no->left) * resolve(no->right);
            break;
        case '/':
            return resolve(no->left) / resolve(no->right);
            break;
        }
    }
    else return no->val;
}


void libera(node *no)
{

    if(no== NULL)
        return;

    libera(no->left);
    libera(no->right);

    free(no);
}

void freeArithTree(ArithTree *t)
{
    libera(t->root);
    return;
}
