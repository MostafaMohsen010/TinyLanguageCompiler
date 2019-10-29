#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
//#define ReservedWordsCount 8
typedef enum {
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, PLUS, MINUS, MULTIPLY, DIVIDE, EQUAL
	, LESS, OPENBARACKET, CLOSEBRASKET ,OPENSQUAREBARACKET, CLOSESQUAREBRASKET, SEMI, ASSIGN, NUMBER, IDENTIFIER
} TokenType;

class TokenRecord {

 public :
	 TokenType tokenval;
	 std::string stringval;
	 int numval;

    TokenRecord(){stringval = "";}
    TokenRecord(TokenType tokenval , std::string stringv , int numv) {
        this->tokenval = tokenval;
        numval =numv;
        stringval = stringv;

    }
    
    void stringify() {
        if (numval == NULL)
        {
            std::cout << stringval << " " << tokenval;
        }
        else
        {
            std::cout << numval << " " << tokenval;
        }

    }


};
TokenRecord getToken (std::string in , bool &isSuccess ) ;
bool isNumLetter ( char in );
//TokenRecord getSpecialCharacterToken ( std::string in ) ;

#endif /*TOKEN_HPP*/
