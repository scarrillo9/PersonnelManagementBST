#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"


BSTree *createTree(){
  BSTree *tree = (BSTree *)malloc(sizeof(BSTree));
  tree->root = NULL;
  return tree;
}//end createTree

BSTNode *createNode(char *name){
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  newNode->name = copyName(name);
  newNode->left = newNode-> right = NULL;
  return newNode;
}//end createNode

char *copyName(char *name){
  char *copy = (char *)malloc(strlen(name+1));
  if(copy != NULL)
    strcpy(copy, name);
  return copy;
}//end copyName

BSTNode *insertNode(BSTNode *root, char *ncopy){
    if(!root){
        return createNode(ncopy);
        //printf("in if %s\n", root->name);
    }//end if creating root node
    
    else if(root){
        if(strcmp(ncopy, root->name) < 0)
            root->left = insertNode(root->left, ncopy);
        else if(strcmp(ncopy, root->name) > 0)
            root->right = insertNode(root->right, ncopy);
    }//end else if
    return root;
    
}//end insertNode

/*
BSTree *insertName(BSTree *tree, char *newName){
    char *ncopy = copyName(newName);
    ncopy[strlen(ncopy)] = '\0';
    
    insertNode(tree->root, ncopy);
    /*
    if(!tree->root){
        tree->root = createNode(ncopy);
    }//end if
    
    else if(tree->root){
        insertNode(tree->root, ncopy);
    }//end else
    /    
    return tree;
}//end insertName
*/

void printNode(BSTNode *root){
    if(root){
        if(root->left)
	  printNode(root->left);
	
        printf("%s", root->name);

	if(root->right)
	  printNode(root->right);
    }//end if
}//end printNode

void printTree(BSTree *tree){
  if(tree->root == NULL)
    printf("List is empty.");
  else
    printf("Printing tree:\n");
    printNode(tree->root);
}//end printTree

BSTNode *delete(BSTNode *root, char* name){

  if(!root)
    return root;

  if(strcmp(name, root->name) < 0)
    root->left = delete(root->left, name);

  else if(strcmp(name, root->name) > 0)
    root->right = delete(root->right, name);

  else if(strcmp(name, root->name) == 0){
    if(root->left && root->right){
      BSTNode *temp = minimumEmployee(root->right);
      root->name = temp->name;
      root->right = delete(root->right, temp->name);
    }//end if root has 2 children
    if(!root->left){
      BSTNode *temp = root->right;
      free(root);
      return temp;
    }//end if left is null
    else if(!root->right){
      BSTNode *temp = root->left;
      free(root);
      return temp;
    }//end if right is null    
  }//end else
  return root;
}//end delete

BSTNode *minimumEmployee(BSTNode *root){
  BSTNode *curr = root;

  while(!curr->left)
    curr = curr->left;

  return curr;
}//end minimum employee


void freeTree(BSTree *tree){
  //doCheck(tree);
  bstFree(tree->root);
  free(tree);
}//end freeTree

void bstFree(BSTNode *root){
  BSTNode *current = root, *right, *left;
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

  root = NULL;
}//end bstFree
