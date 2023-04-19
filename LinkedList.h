/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
	protected:
		struct Node {
			string value; 
			struct Node * next; 
		}; 

	   	Node * head; // list head pointer

	public:
	   	LinkedList(); // DVC
	   	~LinkedList(); // destructor
		  
	   	// common linked list operations
	   	void destroyList();
	   	void displayList();
	   	void insertAtFront(string);
	   	string deleteAtFront();
};

#endif
