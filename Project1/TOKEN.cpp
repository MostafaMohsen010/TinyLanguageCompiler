
#include<string>
#include<stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;

typedef enum {
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, PLUS, MINUS, MULTIPLY, DIVIDE, EQUAL
	, LESS, OPENBARACKET, CLOSEBRASKET, SEMI, ASSIGN, NUMBER, IDENTIFIER
} TokenType;


 class TokenRecord {

 public :
	 TokenType tokenval;
	 string stringval;
	 int numval;


	  TokenRecord(TokenType tokenval) {
		  this->tokenval = tokenval;
		  numval = NULL;
		  stringval = "";

	 }
	  
	  void stringify() {
		  if (numval == NULL)
		  {
			  cout << stringval << " " << tokenval;
		  }
		  else
		  {
			  cout << numval << " " << tokenval;
		  }

	  }


};



 class Parser {

 public :

	 void parse(string in) {
		 in.erase(std::remove_if(in.begin(), in.end(), isspace), in.end());


		 for (int i = 0; i < in.length(); i++)
		 {

		 }


	 }





 };