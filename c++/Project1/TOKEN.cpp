
#include<string>
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef enum {
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, PLUS, MINUS, MULTIPLY, DIVIDE, EQUAL
	, LESS, OPENBARACKET, CLOSEBRASKET ,OPENSQUAREBARACKET, CLOSESQUAREBRASKET, SEMI, ASSIGN, NUMBER, IDENTIFIER
} TokenType;


 class TokenRecord {

 public :
	 TokenType tokenval;
	 string stringval;
	 int numval;


	  TokenRecord(TokenType tokenval , string stringv , int numv) {
		  this->tokenval = tokenval;
		  numval =numv;
		  stringval = stringv;

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

	vector<TokenRecord> parse(string in) {
	//	 in.erase(std::remove_if(in.begin(), in.end(), isspace), in.end());
		 vector <TokenRecord> results;
		 string tmp; bool isReserved;

		 int i=0, j;
		 while (i< in.length())
		 {
			 if (isNumLetter(in[i] ))
			 {
				 j = i ;
				 while (1) {
					 if (!isNumLetter(in[j])) { j--; break; }

					 j++;
				 }
				
				 tmp = in.substr(i, j - i + 1);

				TokenRecord tmpT = getToken(tmp, &isReserved);

				if (isReserved)
				{
					results.push_back(tmpT);
				}
				else 
				{
					results.push_back(TokenRecord(IDENTIFIER, tmp, NULL));

				}

				i = j + 1;

			 }


			 else
			 {

				 switch (in[i])
				 {
				 case '+': results.push_back(TokenRecord(PLUS, "+", NULL)); break;
				 case '-': results.push_back(TokenRecord(MINUS, "+", NULL)); break;
				 case '*': results.push_back(TokenRecord(MULTIPLY, "+", NULL)); break;
				 case '/': results.push_back(TokenRecord(DIVIDE, "+", NULL)); break;
				 case '(': results.push_back(TokenRecord(OPENBARACKET, "+", NULL)); break;
				 case ')': results.push_back(TokenRecord(CLOSEBRASKET, "+", NULL)); break;
				 case '[': results.push_back(TokenRecord(OPENSQUAREBARACKET, "+", NULL)); break;
				 case ']': results.push_back(TokenRecord(CLOSESQUAREBRASKET, "+", NULL)); break;
				 case ';': results.push_back(TokenRecord(SEMI, "+", NULL)); break;
				 case '<': results.push_back(TokenRecord(LESS, "+", NULL)); break;
				 case ':': if (in[i+1]=='=')  results.push_back(TokenRecord(ASSIGN, ":=", NULL)); 
						   else /*error*/	break;
				 case '=': results.push_back(TokenRecord(EQUAL, "=", NULL)); break;
				 case'{':while (true)
							 {
								if (in[i] == '}') break;
								else if (i<in.length()) { i++; }
							//	else /* error */ 
							 } 
						 break;
				 case ' ':break;

				 default: /*error */;
					 break;
				 }

				 i++;

			 }



		 }

		 return results;

	 }





 };