#include <stdio.h>
#include "BSTree.h"


int main(void){

  FILE *filePointer = fopen("names.txt", "r");
  char input[100];
  BSTree *employees = createTree();

  
  if(filePointer == NULL)
    printf("File not found.");
  
  while(fgets(input, 100, filePointer)){
    employees->root = insertNode(employees->root, input);
  }//end while
  
  printTree(employees);

  printf("\n\n");

  getchar();
  char tempdelete[30];
  fgets(tempdelete, 30, stdin);
  employees->root = delete(employees->root, tempdelete);


  //tempdelete[strlen(tempdelete)] = "\0";
  //employees->root = delete(employees->root, tempdelete);

  printTree(employees);
  
  //printTree(employees);
  printf("\n\nEnd of Program\n");

  fclose(filePointer);
  freeTree(employees);
  return 0;
  
}//end main
