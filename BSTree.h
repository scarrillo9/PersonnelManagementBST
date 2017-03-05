#ifndef BSTree_included
#define BSTree_included

typedef struct BSTNode {
  struct BSTNode *right, *left;
  char *name;
} BSTNode;

typedef struct BSTree{
  BSTNode *root;
} BSTree;


//BSTDemo.c methods
void menu(BSTree *employees);

void methods(BSTree *employees, char option);

void makeFile(BSTree *employees);


//BSTree.c methods
//allocates memory for a new tree, nodes and names
BSTree *createTree();

BSTNode *createNode(char *name);

char *copyName(char *name);

//insert method
BSTNode *insertNode(BSTNode *root, char *ncopy);

//print tree methods
void printNode(BSTNode *node);

void inputNamesToFile(BSTNode *root, FILE *file);

void printTree(BSTree *tree);

//delete methods
BSTNode *delete(BSTNode *root, char *name);

BSTNode *minimumEmployee(BSTNode *root);

//free allocated memory methods
void freeTree(BSTree *tree);

void bstFree(BSTNode *tree);

#endif
