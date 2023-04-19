/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#include "LinkedList.h"

/*
Function: LinkedList
Date Created: NA
Date Last Modified: NA
Description: Assignes head to NULL, constructor
Input Parameters:  NA
Output Paramters:  LinkedList
Pre: NA
Post: Returns head as NULL
*/
LinkedList::LinkedList() {
	head = NULL;
}
/*
Function: ~LinkedList
Date Created: NA
Date Last Modified: NA
Description: Destructor for LinkedLists
Input Parameters: NA
Output Paramters: NA
Pre: Would have a linked list to destroy
Post:Destroys the list
*/
LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}
/*
Function: ~LinkedList
Date Created: NA
Date Last Modified: 4/16/23
Description: Destructor for LinkedLists, deletes every node
Input Parameters: NA
Output Paramters: NA
Pre: Would have a linked list to destroy
Post:Destroys the list
*/
void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}
/*
Function: displayList
Date Created: NA
Date Last Modified: 4/16/23
Description: Displays every node in a list
Input Parameters: NA
Output Paramters: Output to console
Pre: Would want to have a list to show
Post: Outputs to console list values
*/
void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

/*
Function: insertAtFront()
Date Created: NA
Date Last Modified: 4/16/23
Description: Add a new string value to front of linked list
Input Parameters: string newValue
Output Paramters: Returns a linked list w one more node
Pre: Must have string Value
Post: Returns updated linked list
*/
void LinkedList::insertAtFront(string newValue) {
Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
  
	// 2 cases
	if (head == NULL) {
		head = newNode;
	} 
	else {
		// list is not empty
		newNode->next = head;
		head = newNode;
	}
}

/*
Function: deleteAtFront
Date Created: NA
Date Last Modified: 4/16/23
Description: Deletes the node at the front of the linked list
Input Parameters: NA
Output Paramters: Updates linked list by deleting front node(if any)
Pre: Must have linked list
Post: Returns linked list minus one node if any to start
*/
string LinkedList::deleteAtFront() {
  string value = "";
  if(head != NULL){
   Node * nodeToDelete = head;
   head = head->next;
   value = nodeToDelete->value;
   delete nodeToDelete;
  }
	return value; // TODO: fix this
}


