/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#include "Stack.h"

/*
Function: push(int)
Date Created: NA
Date Last Modified: 4/16/23 
Description: This function inserts a new value on top of the stack
Input Parameters: string newValue
Output Paramters: updated stack
Pre:  Must have a stack made
Post: updates stack with new value
*/
void Stack::push(string newValue) {
insertAtFront(newValue);
}

/*
Function: pop()
Date Created: NA
Date Last Modified: 4/16/23
Description: Deletes top value on stack
Input Parameters: NA
Output Paramters: Returns stack minus one value
Pre: Must have stack that has value to delete
Post:Returns stack with one less value
*/
string Stack::pop() {
  return deleteAtFront();
}

/*
Function: peek()
Date Created: NA
Date Last Modified: 4/16/23
Description: Return first value of stack
Input Parameters: NA
Output Paramters: Top of stack value
Pre: NA
Post: Returns stack value or NULL if empty
*/
string Stack::peek() {
  if(head == NULL){
	return ""; // TODO: fix this
}
  else{return head->value;}
}

/*
Function: isEmpty
Date Created: NA
Date Last Modified: 4/16/23
Description: Returns a bool if stack is empty
Input Parameters: NA
Output Paramters: Returns true or false
Pre: Must have a stack
Post:Returns whether or not stack is empty
*/
bool Stack::isEmpty() {
  if(head == NULL){
    return true;
  }
	return false; // TODO: fix this
}


