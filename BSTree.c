#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"

//allocating memory for tree
BSTree *createTree(){
  BSTree *tree = (BSTree *)malloc(sizeof(BSTree));
  tree->root = NULL;
  return tree;
}//end createTree

//allocating memory for node
BSTNode *createNode(char *name){
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  newNode->name = copyName(name); //calling name malloc method
  newNode->left = newNode-> right = NULL;
  return newNode;
}//end createNode

//allocating memory for employee name
char *copyName(char *name){
  char *copy = (char *)malloc(strlen(name+1));
  if(copy != NULL)
    strcpy(copy, name);
  return copy;
}//end copyName

//inserting node to tree
BSTNode *insertNode(BSTNode *root, char *ncopy){
    if(!root){
        return createNode(ncopy);
    }//end if creating root node

    //if tree is not empty, look for where to insert
    else if(root){
      //if name is alphanumerically less than current root
      //current employee goes to the left
        if(strcmp(ncopy, root->name) < 0)
            root->left = insertNode(root->left, ncopy);
	//otherwise current employee goes to the right
        else if(strcmp(ncopy, root->name) > 0)
            root->right = insertNode(root->right, ncopy);
	//nothing is inserted if name already exists 
    }//end else if

    return root;
}//end insertNode

//takes root of tree and prints all employee names
void printNode(BSTNode *root){
    if(root){
      if(root->left)
	printNode(root->left);
      printf("%s", root->name);
      if(root->right)
	printNode(root->right);
    }//end if
}//end printNode

//prints names to file
void inputNamesToFile(BSTNode *root, FILE *file){
  if(root){
    if(root->left)
      inputNamesToFile(root->left, file);
    fprintf(file, root->name);
    if(root->right)
      inputNamesToFile(root->right, file);
  }//end if
}//end inputNamesToFile

//checks if tree is null to print error message
//if not calls printNode
void printTree(BSTree *tree){
  if(tree->root == NULL)
    printf("List is empty.");
  else
    printf("\nPrinting tree:\n");
    printNode(tree->root);
}//end printTree

//deletes employee inputted by user from tree if it exists
BSTNode *delete(BSTNode *root, char* name){
  if(!root)
    return root;

  //first checks if name is less than current root to go left
  if(strcmp(name, root->name) < 0)
    root->left = delete(root->left, name);
  //second checks if name is more than current root to go right
  else if(strcmp(name, root->name) > 0)
    root->right = delete(root->right, name);
  //otherwise then the name has been found
  else if(strcmp(name, root->name) == 0){
    //if root has both left and right child
    if(root->left && root->right){
      //finds the smallest employee from the right subtree
      //recursively until tree has shifted and kept it's shape
      BSTNode *temp = minimumEmployee(root->right);
      root->name = temp->name;
      root->right = delete(root->right, temp->name);
    }//end if
    //if root only has right child or is a leaf
    if(!root->left){
      BSTNode *temp = root->right;
      free(root);
      return temp;
    }//end if
    //if root only has left child
    else if(!root->right){
      BSTNode *temp = root->left;
      free(root);
      return temp;
    }//end if
  }//end else
  
  return root;
}//end delete

//finds the minimum employee child from root given
BSTNode *minimumEmployee(BSTNode *root){
  BSTNode *curr = root;

  while(!curr->left)
    curr = curr->left;

  return curr;
}//end minimum employee

//takes in tree to call bstFree
//frees tree struct
void freeTree(BSTree *tree){
  bstFree(tree->root);
  free(tree);
}//end freeTree

//frees all nodes inside tree before returning to freeTree
void bstFree(BSTNode *root){
  BSTNode *current = root, *right, *left;
  left = current->left;

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
