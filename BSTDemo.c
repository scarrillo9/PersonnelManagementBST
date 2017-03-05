#include <stdio.h>
#include <time.h>
#include "BSTree.h"

void menu(BSTree *employees){
  printf("\n\nSelect an option:\n");
  printf("1. Print current employees.\n");
  printf("2. Add new employee.\n");
  printf("3. Remove employee.\n");
  printf("4. Create file with current employee list.\n");
  printf("z. Quit program.\n");

  char option = 'x';
  while(option != 'z'){
    scanf(" %c", &option);
    putchar(option);
    if(option != 'z'){
      methods(employees, option);
    }//end if
  }//end while
  
  printf("\nEnd of program!");
  //freeTree(employees);
  return;
}//end menu

void methods(BSTree *employees, char option){
  switch(option){
  case '1':
    printTree(employees);
    //menu(employees);
    break;
  case '2':
    getchar();
    char newName[30];
    printf("\nEnter new employee:");
    fgets(newName, 30, stdin);
    employees->root = insertNode(employees->root, newName);
    printf("\nNew employee %s has been added.", newName);
    //menu(employees);
    break;
  case '3':
    getchar();
    char deleteName[30];
    printf("\nEnter employee to delete:");
    fgets(deleteName, 30, stdin);
    employees->root = delete(employees->root, deleteName);
    printf("\nEmployee %s has been deleted.", deleteName);
    //menu(employees);
    break;
  case 'd':
    makeFile(employees);
    printf("\nA file named EmployeesList.txt has been created.");
    //menu(employees);
    break;
  case 'z':
    break;
  default:
    printf("\nInvalid entry.");
  }//end switch
  menu(employees);
  return;
}//end methods

void makeFile(BSTree *employees){
  FILE *newFile = fopen("EmployeesList.txt", "w");
  if(newFile == NULL)
    printf("Couldn't open file.\n");

  char buffer[50];
  time_t now = time(0);
  strftime(buffer, 50, "Employees as of %Y-%m-%d %H:%M:%S\n\n", localtime(&now));
  fprintf(newFile, buffer);

  inputNamesToFile(employees->root, newFile);
  fclose(newFile);
}//end makeFile

int main(void){

  FILE *filePointer = fopen("names.txt", "r");
  char input[100];
  BSTree *employees = createTree();

  
  if(filePointer == NULL)
    printf("File not found.");
  
  while(fgets(input, 100, filePointer)){
    employees->root = insertNode(employees->root, input);
  }//end while

  menu(employees);
  
  fclose(filePointer);
  freeTree(employees);
  return 0;
  
}//end main
