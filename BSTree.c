#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"

//int llDoCheck = 1;
//#define doCheck(_lp) (llDoCheck && llCheck(_lp))


BSTree *createTree(){
  BSTree *tree = (BSTree *)malloc(sizeof(BSTree));
  //doCheck(tree);
  tree->root = NULL;
  return tree;
}//end createTree

BSTNode *createNode(char *name){
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  newNode->name = name;
  newNode->left = newNode-> right = NULL;
  //doCheck(tree);
  return newNode;
}//end createNode

void freeTree(BSTree **tree){
  //doCheck(tree);
  BSTree *this_tree = *tree;
  bstFree(&this_tree);
  free(tree);
}//end freeTree

void bstFree(BSTree **tree){
  BSTree *this_tree = *tree;
  BSTNode *current = this_tree->root, *right, *left;
  left = current->left;
  //doCheck(tree);

  while(current){
    right = current->right;
    free(current->name);
    free(current);
    current = right;
  }//end while

  current = left;
  while(current){
    left = current->left;
    free(current->name);
    free(current);
    current = left;
  }//end while

  this_tree->root = NULL;
}//end bstFree

void insertName(BSTree **tree, char *newName){
  BSTree *this_tree = *tree;
  if(this_tree->root == NULL){
    this_tree->root = createNode(newName);
    return;
  }//end if
  
  if(this_tree->root != NULL){
    printf("In else");
    insert(&(this_tree->root), newName);
  }//end else
}//end insertName

void insert(BSTNode **root, char *newName){
  BSTNode *this_root = *root;
  int i = 0;

  while(this_root->name[i] != '/' || newName[i] != '/'){
    if(this_root->name[i] > newName[i])
      insert(&(this_root->left), newName);

    if(this_root->name[i] < newName[i])
      insert(&(this_root->right), newName);

    else
      i = i + 1;
  }//end while

  if(this_root->name[i] == '/')
    insert(&(this_root->right), newName);
  if(newName[i] == '/')
    insert(&(this_root->left), newName);
}//end insert

void printTree(BSTree **tree){
  BSTree *this_tree = *tree;
  if(this_tree->root == NULL)
    printf("List is empty.");
  else
    print(&(this_tree->root));
}//end printTree

void print(BSTNode **root){
  BSTNode *this_root = *root;
  if(this_root->left)
    print(&(this_root->left));

  printf("%s", this_root->name);

  if(this_root->right)
    print(&(this_root->right));
}//end print

/*
int llCheck(BSTree *tree){
  BSTNode *root;
  root = tree->root;
  if(!root)
    assert(root->name == NULL);
  else{

    //TODO
    //CHECKS ALL NODES

  }//end else
}//end llCheck
*/
