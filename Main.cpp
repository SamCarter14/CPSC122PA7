/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#include "PA7.h"

int main() {
ifstream inFile;
Stack stack;
Calculator calc;
  carryOutPA7(inFile, stack, calc);
	return 0;
}
