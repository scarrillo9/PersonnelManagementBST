# Arch1 Binary Search Tree Personnel Management System

This directory contains:
* code that implements a binary search tree of strings 
* a demo program that uses it

The demo program reads lines from a text file (names.txt).
Each line is inserted into the binary search tree based on alphanumeric value.
After end-of-file is read, a menu is shown with the options of either printing,
adding a new employee, deleting an employee, and making a file with the list of
current employees.

This demo contains the following files:
 BSTree.h: header file of the binary search tree structure & "public" interface
 	   functions.
 BSTree.c: implementation of the binary search tree with all insert, delete,
 	   and print functions.
 BSTDemo.c: a demonstration program that uses the binary search tree.
 names.txt: a sample file to be read by the demo file to implement the binary
 	    search tree.
 EmployeesList.txt: once demo has ran and option 4 has been chosen,
           	    EmployeesList.txt will be available.

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ ./BSTDemo
~~~

To delete binaries:
~~~
$ make clean
~~~

When the program is first run, it will create the current binary search tree
with the text file provided, and then the option menu will prompt the user for
an action.

if the user prompts 1) Print current employees:
~~~
The program will print all employees in the tree based on the binary search
tree structure. Once the printing is done, user will be taken back to main menu.
~~~

if the user prompts 2) Add new employee:
~~~
The program will prompt the user for the name of an employee to add to the
tree. If employee already exists in the tree, it will not be added to the tree
again and the user will come across the menu options again.
~~~

if the user prompts 3) Remove employee:
~~~
The program will prompt the user for the name of an employee to delete from
the tree. If employee doesn't exist, nothing will be deleted and the user
will be taken back to the main menu options.
~~~

if the user prompts 4) Create file with current employee list:
~~~
   The program will create a new file named EmployeesList.txt with the names of
   all the employees currently in the binary search tree based on the structure
   of the tree. If 4 is pressed again in a future, the text file will only be
   updated with the employees at the moment.
~~~

if the user prompts z) Quit program:
~~~
   This command ends the program and frees the current binary search tree.
~~~

Code and help obtained:
     * How to print time and date (for option 4 to put at beginning of new file)
       stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
     * Got help from Ana Garcia on how to scan for user input in BSTDemo.c
     * Refresher on how binary search trees work
       quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
       quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/