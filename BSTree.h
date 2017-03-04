#ifndef BSTree_included
#define BSTree_included

typedef struct BSTNode {
  struct BSTNode *right, *left;
  char *name;
} BSTNode;

typedef struct BSTree{
  BSTNode *root;
} BSTree;


//allocates memory for a new tree
BSTree *createTree();

BSTNode *createNode(char *name);

char *copyName(char *name);



BSTNode *insertNode(BSTNode *root, char *ncopy);

//BSTree *insertName(BSTree *tree, char *newName);



void printNode(BSTNode *node);

void printTree(BSTree *tree);


BSTNode *delete(BSTNode *root, char *name);

BSTNode *minimumEmployee(BSTNode *root);

//free allocated memory
void freeTree(BSTree *tree);

void bstFree(BSTNode *tree);



#endif
