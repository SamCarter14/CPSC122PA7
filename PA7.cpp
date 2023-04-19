/*
 Name: Sam Carter
 Class: CPSC 122 Spring
 Date: April 18 2023
 Programming Assignment: PA7                                                         
 Description: This program converts infix expressions to postfix expressions and then evaluates those postfix expressions using a stack.
 Notes: 
*/
#include "PA7.h"
#include "Calculator.h"

/*
Function: carryOutPA7
Date Created: 4/16/23
Date Last Modified: 4/18/23
Description: This function reads the input file and uses helper functions to carry out PA7
Input Parameters: ifstream & inFile, Stack stack, Calculator calc
Output Paramters: Finishes the entire program
Pre: Must have file to read, Calc and a stack
Post:
*/
void carryOutPA7(ifstream & inFile, Stack stack, Calculator calc){
  
  string infix, postfix;
  char temp;
  inFile.open("../input.txt");
string symbolTable['Z' + 1];

  inFile >> temp;
  while(temp != '#'){
    switch(temp){
      case 'A' :{
        string As;
        inFile >> As;
     symbolTable['A'] = As;
      break;}
      
      case 'B' :{
      string Bs;
        inFile >> Bs;
     symbolTable['B'] = Bs;
      break;}
      
      case 'C' :{
      string Cs;
        inFile >> Cs;
     symbolTable['C'] = Cs;
      break;}
      
      case 'D' :{
      string Ds;
        inFile >> Ds;
     symbolTable['D'] = Ds;
      break;}

      case 'E' :{
      string Es;
        inFile >> Es;
     symbolTable['E'] = Es;
      break;}

      case 'F' :{
      string Fs;
        inFile >> Fs;
     symbolTable['F'] = Fs;
      break;}

      case 'G' :{
      string Gs;
        inFile >> Gs;
     symbolTable['G'] = Gs;
      break;}

      case 'H' :{
      string Hs;
        inFile >> Hs;
     symbolTable['H'] = Hs;
      break;}

      case 'I' :{
      string Is;
        inFile >> Is;
     symbolTable['I'] = Is;
      break;}

      case 'J' :{
      string Js;
        inFile >> Js;
     symbolTable['J'] = Js;
      break;}

      case 'K' :{
      string Ks;
        inFile >> Ks;
     symbolTable['K'] = Ks;
      break;}

      case 'L' :{
      string Ls;
        inFile >> Ls;
     symbolTable['L'] = Ls;
      break;}

      case 'M' :{
      string Ms;
        inFile >> Ms;
     symbolTable['M'] = Ms;
      break;}

      case 'N' :{
      string Ns;
        inFile >> Ns;
     symbolTable['N'] = Ns;
      break;}

      case 'O' :{
      string Os;
        inFile >> Os;
     symbolTable['O'] = Os;
      break;}

      case 'P' :{
      string Ps;
        inFile >> Ps;
     symbolTable['P'] = Ps;
      break;}

      case 'Q' :{
      string Qs;
        inFile >> Qs;
     symbolTable['Q'] = Qs;
      break;}

      case 'R' :{
      string Rs;
        inFile >> Rs;
     symbolTable['R'] = Rs;
      break;}

      case 'S' :{
      string Ss;
        inFile >> Ss;
     symbolTable['S'] = Ss;
      break;}

      case 'T' :{
      string Ts;
        inFile >> Ts;
     symbolTable['T'] = Ts;
      break;}

      case 'U' :{
      string Us;
        inFile >> Us;
     symbolTable['U'] = Us;
      break;}

      case 'V' :{
      string Vs;
        inFile >> Vs;
     symbolTable['V'] = Vs;
      break;}

      case 'W' :{
      string Ws;
        inFile >> Ws;
     symbolTable['W'] = Ws;
      break;}

      case 'X' :{
      string Xs;
        inFile >> Xs;
     symbolTable['X'] = Xs;
      break;}

      case 'Y' :{
      string Ys;
        inFile >> Ys;
     symbolTable['Y'] = Ys;
      break;}

      default :{
      string Zs;
        inFile >> Zs;
     symbolTable['Z'] = Zs;
      break;}
    }
    inFile >> temp;
  }

  calc.setSymbolTable(symbolTable);
  inFile >> infix;
while(infix != "#"){
  cout << "Infix expression: " << infix << endl;
  postfix = calc.convertInfixToPostfix(infix);
  cout << "Postfix expression: " << postfix << endl;
  cout << "Expression value after postfix evaluation: "<< calc.evaluatePostfix(postfix) << endl;
  inFile >> infix;
}
  inFile.close();
}




