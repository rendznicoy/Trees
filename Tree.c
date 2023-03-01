#include "Tree.h"

BTNODE BTNODE_createNewNode(TElement newData)
{
    BTNODE n = (BTNODE)malloc(sizeof(struct _btnode));
    n->data = newData;
    n->left = n->right = NULL;
    return n;
}

BTNODE BTNODE_insert(BTNODE node, TElement data)
{
    if(node == NULL)
        return BTNODE_createNewNode(data);

    if(data < node->data)
        node->left = BTNODE_insert(node->left, data);
    else
        node->right = BTNODE_insert(node->right, data);
    
    return node;
}

BTNODE BTNODE_findChild(BTNODE node)
{
    BTNODE current = node;
    
    while(current && current->left != NULL)
        current = current->left;
    
    return current;
}

BTNODE BTNODE_delete(BTNODE root, TElement data)
{
    if(root == NULL)
        return root;
    
    if(data < root->data)
        root->left = BTNODE_delete(root->left, data);
    else if(data > root->data)
        root->right = BTNODE_delete(root->right, data);
    
    else
    {
        if(root->left == NULL)
        {
            BTNODE d = root->right;
            free(root);
            return d;
        }
        else if (root->right == NULL)
        {
            BTNODE d = root->left;
            free(root);
            return d;
        }

        BTNODE del = BTNODE_findChild(root->right);
        root->data = del->data;
        root->right = BTNODE_delete(root->right, del->data);
    }
    return root;
}

int BTNODE_search(BTNODE root, TElement data)
{
    int f = 1;
    while(root != NULL)
    {
        if(data > root->data)
            root = root->right;
        else if(data < root->data)
            root = root->left;
        else
            return f;
    }
    return -1;   
}

int minValue(BTNODE node)
{
    BTNODE current = node;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}

int maxValue(BTNODE node)
{
    BTNODE current = node;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return(current->data);
}
int BTNODE_levelUtil(BTNODE node)
{
    if(node == NULL)
        return 0;
    else
    {
        int leftHeight = BTNODE_levelUtil(node->left);
        int rightHeight = BTNODE_levelUtil(node->right);
        if(leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int BTNODE_level(BTNODE node)
{
    return BTNODE_levelUtil(node) - 1;
}

int BTNODE_height(BTNODE node)
{
    return BTNODE_levelUtil(node);
}

int BTNODE_computeLevelUtil(BTNODE node, TElement data, TElement level)
{
    if(node == NULL)
        return 0;
    if(node->data == data)
        return level;
    int downLevel = BTNODE_computeLevelUtil(node->left, data, level + 1);
    if(downLevel != 0)
        return downLevel;
    downLevel = BTNODE_computeLevelUtil(node->right, data, level + 1);
    return downLevel;
}

int BTNODE_computeLevel(BTNODE node, TElement data)
{
    return BTNODE_computeLevelUtil(node, data, 1) - 1;
}

int BTNODE_computeHeight(BTNODE node, TElement data)
{
    return BTNODE_computeLevelUtil(node, data, 1);
}

int BTNODE_countLeaf(BTNODE node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return BTNODE_countLeaf(node->left) + BTNODE_countLeaf(node->right);
}

void BTNODE_preOrder(BTNODE root)
{
    if(root != NULL)
    {
        printf("%d -> ", root->data);
        BTNODE_preOrder(root->left);
        BTNODE_preOrder(root->right);
    }
}
void BTNODE_inOrder(BTNODE root)
{
    if(root != NULL)
    {
        BTNODE_inOrder(root->left);
        printf("%d -> ", root->data);
        BTNODE_inOrder(root->right);
    }
}

void BTNODE_postOrder(BTNODE root)
{
    if(root != NULL)
    {
        BTNODE_postOrder(root->left);
        BTNODE_postOrder(root->right);
        printf("%d -> ", root->data);
    }
}

void BTNODE_BFUtil(BTNODE root)
{
    TElement h = BTNODE_height(root);
    int i;
    for(i = 1; i <= h; i++)
        BTNODE_BFTraversal(root, i);
}

void BTNODE_BFTraversal(BTNODE root, TElement level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d -> ", root->data);
    else if(level > 1)
    {
        BTNODE_BFTraversal(root->left, level - 1);
        BTNODE_BFTraversal(root->right, level - 1);
    }
}