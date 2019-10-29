#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <vector>
#include"TOKEN.hpp"

using namespace std;

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

				TokenRecord tmpT = getToken(tmp, isReserved);

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
				 case '{':while (true)
							 {
								if (in[i] == '}') break;
								else if (i<in.length()) { i++; }
							//	else /* error */ 
							 } 
						 break;
				 case ' ':
				 case '\n':	 break;

				 default: /*error */;
					 break;
				 }

				 i++;

			 }



		 }

		 return results;

	 }





 };

#endif /*PARSER_HPP*/