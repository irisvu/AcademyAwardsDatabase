DISCRIPTION
-----------

Authors: Josh Mansito and Iris Vucic
Date Created: 12/01/2020
IDE's used: Visual Studio, CLION, Repl.it

Program: CSCI 2421: Data Structures and Program DesignFinal Project
Purpose: 

"Given the requirements as a rough specification, you are to design the classes and implement the database. 
So you can consider the requirements below as an outcome from a meeting with a client. 
You are in full control of the choice of data structures, algorithms, and detailed user interface scheme."

We were instructed to create a program designed to navigate and manipulate two different types of csv files. Multiple Functions must be 
working in order to meet all requirements lsited in the Final Project instructions


--------------------------------------------------------------

MAKEFILE: 
1) make
2) ./tree

---------------------------------------------------------------

FILES:

main.cpp
	- Used to initially split up the two databases
	- Allows the user to choose which to pick then calls the functions for the database selected

Menu.cpp
Menu.h
	- Holds all of the text driven functions for user interaction with the program
	- All functions pull from these when user interaction is required

BSTree.cpp
BSTree.h
	
	- Main files for all tree manipulation
	- Holds the trees and allows us to navigate them and manipulate as need for the database functions

actor.cpp
actor.h

	- Class to let us create the actor tree and all of its variables
	- Holds the "fields" of the actor/actress database

pictures.cpp
pictures.h

	- Class to let us create the pictures tree and all of its variables
	- Holds the "fields" of the pictures database

actBinaryTree.cpp
actBinaryTree.h

	- MAIN files for all actor / actress database functions
	- Does all function calls and steps to manipulate the database
	- 1st of the 2 parts of the program that houses the majority of all functions
	- Currently missing Modify function

picBinaryTree.cpp
picBinaryTree.h

	- MAIN files for all pictures database functions
	- Does all function calls and steps to manipulate the database
	- 2nd of the 2 parts of the program that houses the majority of all functions
	- Currently missing Modify function
	- Currently missing the required tree manipulation to run the delete function


actor-actress.csv
pictures.csv

	- Included with instructions
	- Project is currently set to read them in


makefile
readme

---------------------------------------------------------------

THOUGHTS ON ASSIGNMENT:

This project was a challenge but also rewarding and tought us a lot about data structures. 
The main obsticle we ran into was the deletion function, to acomplish it, we had to make a lot of extra functions
for searching, deleting, tree traversal, and node deletion. We could have modified the current functions to acomplish this same thing
but that would have required a complete rework and redesign of the program. 

The menu system was more challenging than originally planned, and it has much more control than we were expecting. There were
a lot of updates and changes done to the menu logic to try and get it to work with our functions and error checking. 

The error checking system was something that saved us a lot of time. Instead of error checking or try catching inside of each function, 
we made a umbrella error checking system for the databases and the menus that took specific parameters and error checked against
the given parameters. It is not the ideal solution to dealing with a lot of the errors that can happen from user input, and would
need to be fleshed out a lot more in order for it to work the way we want, but it saved us a lot of development time regardless. 


----------------------------------------------------------------

CITED SOURCES:

https://www.geeksforgeeks.org/binary-search-tree-data-structure/
https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
https://stackoverflow.com/questions/33645141/binary-search-tree-sorted/33649922#33649922
https://stackoverflow.com/questions/19936483/c-reading-csv-file
https://stackoverflow.com/questions/25201131/writing-csv-files-from-c