#include <stdio.h>
#include "BSTree.h"


int main(void){
/*  FILE *filePointer = fopen("names.txt", "r");
  char input[100] = "";
  BSTree *employees = createTree();

  if(filePointer == NULL)
    printf("File not found.");
  
  */

    BSTNode *temptree = createNode("b");
    insertNode(temptree, "a");
    printNode(temptree);
    
    //printf("in main: %s \n",temptree->right->name);

//  while(fgets(input, 100, filePointer)){
//    printf(input);
//    insertName(&employees, input);
//  }//end while

  //printTree(&employees);
  //printf("\n\nEnd of Program\n");

  //fclose(filePointer);
  //freeTree(&employees);
  //return 0;
  
}//end main
