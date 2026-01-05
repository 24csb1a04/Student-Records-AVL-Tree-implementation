# Student-Records-AVL-Tree-implementation
A college assignment which uses the AVL Tree Data structure to store student records based on roll number/marks as the key to speed up student look up due to O(nlogn) time complexity of AVL Tree
# Project Directory Structure
courseinfo.h :  A header file defining the struct "course" that will be later used for storing student course data
node.h       :  A header file that defines the struct "node" which is the fundamental unit of AVL Tree.
filehandler.h:  Defines a filehandler struct that will be used for parsing input file in the required format.
AVL_TREE.h   : Declares all the functions of AVL Tree structure that need to be implemented.
node_operations.cpp : Implements all the functionalities of node struct.
AVL_TREE.cpp : Implements all the functionalities of AVL TREE struct defined earlier in AVL_TREE.h
filehandler.cpp : Implements all the functions defined in filehandler.h to parse the input file.
main.cpp : Main file of the project. Takes name and key of the AVL TREE (roll no / marks) as input through command-line arguments and implements the complete project.
