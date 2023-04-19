/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#include "Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
Function: setSymbolTable
Date Created: NA
Date Last Modified: NA 
Description: This function updates symbolTable array by copying values from a new array
Input Parameters: string newSymbolTable[]
Output Paramters: updated symbolTable[]
Pre: Must have newSymbolTable array
Post: Returns an ipdated symbolTable Array
*/
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

/*
Function: checkOperatorOnStackPrecedence()
Date Created: NA
Date Last Modified: 4/17/23
Description: Returns true or false based on precedence for postfix expressions
Input Parameters: string operatorOnStack, string currentOperator
Output Paramters: Outputs true or false
Pre: Must have two string values that are an operator
Post: Returns true or false based on precedence
*/
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
	int operatorOnStackValue = 0;
  int currentOperatorValue = 0;

  if(operatorOnStack == ")"){
    operatorOnStackValue = -1;
  }
  else if(operatorOnStack == "-" || operatorOnStack == "+"){
    operatorOnStackValue = 2;
  }
  else if(operatorOnStack == "*" || operatorOnStack == "/" || operatorOnStack == "%"){
    operatorOnStackValue = 4;
  }
  else if(operatorOnStack == "^"){
    operatorOnStackValue = 5;
  }
  else{operatorOnStackValue = 0;}
  
    if(currentOperator == ")"){
    currentOperatorValue = 0;
  }
  else if(currentOperator == "-" || currentOperator == "+"){
    currentOperatorValue = 1;
  }
  else if(currentOperator == "*" || currentOperator == "/" || currentOperator == "%"){
    currentOperatorValue = 3;
  }
  else if(currentOperator == "^"){
    currentOperatorValue = 6;
  }
  else{currentOperatorValue = 100;}

  if(operatorOnStackValue > currentOperatorValue){
    return true;
  }
  return false; 
}

/*
Function: convertInfixToPostfix
Date Created: NA
Date Last Modified: 4/17/23
Description: This function converts and infix string to postfix
Input Parameters: string infix
Output Paramters: string postfix
Pre: Must have read in an infix string
Post: Will convert infix string to postfix form 
*/
string Calculator::convertInfixToPostfix(string infix) {
  Stack postfixStack;
  string item, postfix, temp;
  
  for(int i = 0; i < infix.size(); i++){
    item = infix.at(i);
    if(isalpha(infix.at(i))){
      postfix.append(item);
    }
    else if(item == "("){
      postfixStack.push(item);
    }
    else if(item == ")"){
      while(postfixStack.peek() != "("){
        temp = postfixStack.pop();
        postfix.append(temp);
      }
      postfixStack.pop();
    }
    else{
      while(postfixStack.isEmpty() == false && checkOperatorOnStackPrecedence(postfixStack.peek(), item) == true){
        temp = postfixStack.pop();
        postfix.append(temp);
      }
      postfixStack.push(item);
    }
  }
  while(postfixStack.isEmpty() == false){
    temp = postfixStack.pop();
    postfix.append(temp);
  }
	   return postfix; 
}

/*
Function: evaluatePostfix
Date Created: NA
Date Last Modified: 4/17/23 
Description: This function takes the postfix expression and converts it into actual math and evaluates it.
Input Parameters: string postfix
Output Paramters: string operation
Pre: Must have converted infix string into postfix expression.
Post: Returns a math number as a string
*/
string Calculator::evaluatePostfix(string postfix) {
  Stack postfixStack;
  string temp, operation, item, symbol, operationNew;
  if(postfix.size() == 1){
    return symbolTable[postfix.at(0)];
  }
  for(int i = 0; i < postfix.size(); i++){
    item = postfix.at(i);
  if(item != "/" && item != "%" && item !="*" && item !="+" && item != "-" && item != "^" && item != "(" && item != ")"){
    postfixStack.push(item);
  }
    else{
      operation = item;
      operation.append(postfixStack.pop());
      operation.insert(0, postfixStack.pop());
      // cout << "Pre Convert Operation: " << operation << endl;
      operation = convertExpression(operation);
      // cout << endl << operation << endl;
      //cout << operation << " = ";
      operation = evaluateExpression(operation);
      if(operation == "ERROR"){
        continue;
      }
      //cout << operation << endl;
      postfixStack.push(operation);
    }

    
  }
  operation = postfixStack.pop();
  //cout << "Done" << endl;
  return operation; 
}
/*
Function: convertExpression
Date Created: 4/16/23
Date Last Modified: 4/17/23
Description: This is a helper function that actually goes through the string operation and converts the letters into numbers
Input Parameters:  string operation
Output Paramters:  string newOperation
Pre: Takes something like A+B and turns it into something like
Post:22+55
*/
string Calculator::convertExpression(string operation){
  string symbol, valueString, newOperation = "", holder, symbol1;
  char letter;
  int num;
  for (int i = 0; i < operation.size(); i++){
    if (isalpha(operation.at(i))){
  symbol = symbolTable[operation.at(i)];
      symbol1 = symbol;
      num = stoi(symbol1);
      holder = to_string(num);
  }
    else{holder = operation.at(i);}
    
    newOperation.append(holder);
  }
  return newOperation;
}


/*
Function: evaluateExpression
Date Created: 4/16/23
Date Last Modified: 4/17/23
Description: This function takes in a string operation and does the actual math for the operation
Input Parameters: string operation
Output Paramters: string operation
Pre: Must have a string with numbers, such as 22+55
Post:Returns the result for those numbers as a string, like 77
*/


string Calculator::evaluateExpression(string operation){
     //cout << "Operation: " << operation << endl;
  string tempString, tempChar, operate;
  long value1, value2, value3 = 0;
  for(int i = 0; i < operation.size(); i++){
    if(tempString == ""){
      tempChar = operation.at(i);
      tempString.insert(0, tempChar);
    }
    else if(isdigit(operation.at(i))){
      tempChar = operation.at(i);
      tempString.append(tempChar);
    }
    else{
      value1 = stol(tempString);
      tempString = "";
      operate = operation.at(i);
    }
  }
  value2 = stol(tempString);
// cout << "Value 1: " << value1 << endl << "Value 2: " << value2 << endl;
if(operate == "*"){
  operation =  to_string(value1 * value2);
}
else if(operate == "/" || operate == "%"){
  if(value2 == 0){
    return "ERROR";
  }
  operation = to_string(value1 / value2);
}
else if(operate == "+"){
  operation = to_string(value1 + value2);
}
else if(operate == "-"){
  operation = to_string(value1 - value2);
}
else{value3 = (pow(value1, value2));
    operation = to_string(value3);}
 // cout << "outcome: " << operation << endl << endl;
  return operation;
}