#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TElement;

typedef struct _btnode
{
	TElement data;
	struct _btnode* left;
	struct _btnode* right;
} *BTNODE;

typedef struct _binarytree
{
	BTNODE root;
} *BINARYTREE;

BTNODE BTNODE_createNewNode(TElement newData);
BTNODE BTNODE_insert(BTNODE node, TElement data);
BTNODE BTNODE_findChild(BTNODE node);
BTNODE BTNODE_delete(BTNODE root, TElement data);
int BTNODE_levelUtil(BTNODE node);
int BTNODE_level(BTNODE node);
int BTNODE_height(BTNODE node);
int BTNODE_computeLevelUtil(BTNODE node, TElement data, TElement level);
int BTNODE_computeLevel(BTNODE node, TElement data);
int BTNODE_computeHeight(BTNODE node, TElement data);
int BTNODE_countLeaf(BTNODE node);
int BTNODE_search(BTNODE root, TElement data);
int minValue(BTNODE node);
int maxValue(BTNODE node);
void BTNODE_preOrder(BTNODE root);
void BTNODE_inOrder(BTNODE root);
void BTNODE_postOrder(BTNODE root);
void BTNODE_BFUtil(BTNODE root);
void BTNODE_BFTraversal(BTNODE root, TElement level);

#endif