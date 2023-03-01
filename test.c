#include "Tree.h"

int main()
{
    BTNODE root = NULL;
    root = BTNODE_insert(root, 50);
    root = BTNODE_insert(root, 30);
    root = BTNODE_insert(root, 20);
    root = BTNODE_insert(root, 40);
    root = BTNODE_insert(root, 70);
    root = BTNODE_insert(root, 60);
    root = BTNODE_insert(root, 80);
    root = BTNODE_insert(root, 81);
    root = BTNODE_insert(root, 83);
    root = BTNODE_insert(root, 86);
    if(BTNODE_search(root, 50))
        printf("The number is present in the tree");
    else  
        printf("The number isn't present in the tree");
    
    printf("\n Minimum value in BST is %d", minValue(root));
    printf("\n Maximum value in BST is %d", maxValue(root));
    return 0;
}