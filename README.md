# Student-Database
Overview:
---------------------------------------------------------------------------------------------------------------------------------------
Database that stores student information in one singly linked list and three skip lists. The SLL holds all students in the order they were added, the first SKL by GPA from highest to lowest, the second SKL by major from lowest to highest (where major is an integer value), the third SKL by group ID from lowest to highest (where group ID is an integer). The user is able to add, delete and print students.

Purpose of program:
---------------------------------------------------------------------------------------------------------------------------------------
The purpose of this program is to demonstrate clear understanding of pointers and to delve into the purpose and methods behind linking objects. This program may be more easily programmed using a doubly linked list, but a singly linked list was chosen because it was more difficult and stressed me to better understand what was occuring within the linked list when objects were deleted or added.

Objects used and their variables:
---------------------------------------------------------------------------------------------------------------------------------------
Student:			string* name | string* username | float* gpa | int* major | int* groupid

Node:         Student* data | Node* next | Node* skipnext

SLL:          Node* head | Node* skipprevious | Node* tail

Description of objects:
---------------------------------------------------------------------------------------------------------------------------------------
The Student object holds all information about each student that has been added to the linked list.

The Node object holds a student object "data", a node object "next" which points to the next node in the linked list, and a node object "skipnext" which points to the next "range" in the list.

The SLL object holds a node object "head" which points to the first node within the linked list, a node object "skipprevious" which is used to point to nodes whose skipnext field is not the null pointer, and a "tail" which is used to quickly add additional nodes within the first SLL.

How it works:
---------------------------------------------------------------------------------------------------------------------------------------
The program allows user to add one student at a time, delete one student at a time, and print students within a certain range either by GPA, major, or group ID.  The range for GPA is in .5 decrements from 4.0 to 0.0 (i.e. 4.0-3.5, 3.49-3.0, etc.)  The range for major is one integer (i.e. 0, 100, 200, etc.). The range for group ID is one integer (i.e. 0, 1, 2, etc.).  The program prompts the user to ask if they would like to add, delete or print a student.  

When a student is added, the student object is stored within a node and the program then parses through the list until it finds the correct location for the node in order of GPA, major, or group ID. 

When a student is deleted, the program parses through the list until it finds the node with the correct student name, and subsequently reallocates the next and skipnext fields of surrounding nodes as needed before deleting the node.  

When the user wishes to print a range of students, the program prompts the user whether they would like to print by order of GPA, major, or group ID, and prompts again for the range the user would like to print.  All students within the selected range are then printed to screen.

When the user wishes to end the program, they only need enter "no" when prompted "Would you like to continue the program?".
