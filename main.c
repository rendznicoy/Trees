#include "Tree.h"

int main()
{
    BTNODE root = NULL;
    root = BTNODE_insert(root, 25);
    root = BTNODE_insert(root, 15);
    root = BTNODE_insert(root, 10);
    root = BTNODE_insert(root, 4);
    root = BTNODE_insert(root, 12);
    root = BTNODE_insert(root, 22);
    root = BTNODE_insert(root, 18);
    root = BTNODE_insert(root, 24);
    root = BTNODE_insert(root, 50);
    root = BTNODE_insert(root, 35);
    root = BTNODE_delete(root, 25);

    printf("Pre-Order: ");
    BTNODE_preOrder(root);
    printf("\n");
    printf("Inorder: ");
    BTNODE_inOrder(root);
    printf("\n");
    printf("Post-Order: ");
    BTNODE_postOrder(root);
    printf("\n");
    printf("Breadth First Traversal: ");
    BTNODE_BFUtil(root);
    printf("\n");
    printf("Leaf Count: %d", BTNODE_countLeaf(root));
    printf("\n");
    printf("Level of tree: %d", BTNODE_level(root));
    printf("\n");
    printf("Height of tree: %d", BTNODE_height(root));
    printf("\n");

    /*for(int i = 1; i <= 10; i++)
    {
        int level = BTNODE_computeLevel(root, i);
        if(level)
        {
            printf("Level of %d is: %d", i, BTNODE_computeLevel(root, i));
            printf("\n");
        }
        else
        {
            printf("%d isn't present in the tree", i);
            printf("\n");
        }
    }

    for(int i = 1; i <= 10; i++)
    {
        int level = BTNODE_computeHeight(root, i);
        if(level)
        {
            printf("Height of %d is: %d", i, BTNODE_computeHeight(root, i));
            printf("\n");
        }
        else
        {
            printf("%d isn't present in the tree", i);
            printf("\n");
        }
    }*/

}