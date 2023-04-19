/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);
    Stack fillInfixStack(string);
    string convertExpression(string operation);
    string evaluateExpression(string operation);
};

#endif