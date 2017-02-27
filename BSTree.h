#ifndef BSTree_included
#define BSTree_included

typedef struct BSTNode {
  struct BSTNode *right, *left;
  char *name;
} BSTNode;

typedef struct BSTree{
  BSTNode *root;
} BSTree;

//extern int llDoCheck;


//allocates memory for a new tree
BSTree *createTree();

BSTNode *createNode(char *name);


//free allocated memory
void freeTree(BSTree **tree);

void bstFree(BSTree **tree);


//inserting nodes into tree
void insertName(BSTree **tree, char *employee);

void insert(BSTNode **root, char *newName);


//cheacks if list is empty
void printTree(BSTree **tree);

//prints employees
void print(BSTNode **root);


//checks tree consistency, always returns 0
//int llCheck(BSTree *tree);

#endif
