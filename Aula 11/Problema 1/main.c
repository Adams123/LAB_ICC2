#include "ArithTree.h"

int main()
{
    char input[3000];
    fgets(input,3000,stdin);
    ArithTree *tree = createArithTree();
    buildArithTree(tree,input);
    printInOrder(tree);
    freeArithTree(tree);
    return 0;
}
