#include"TOKEN.hpp"

//using namespace std;
#define first_num_in_Ascii 48
#define last_num_in_Ascii 58
#define first_cap_in_Ascii 65
#define last_cap_in_Ascii 91
#define first_small_in_Ascii 97
#define last_small_in_Ascii 123
TokenRecord getToken (std::string in , bool &isSuccess )    //Not Tested 
{
    isSuccess = true;
    if(in=="IF")
        return TokenRecord(IF,"IF",NULL);
    if(in=="THEN")
        return TokenRecord(THEN,"THEN",NULL);
    if(in=="ELSE")
        return TokenRecord(ELSE,"ELSE",NULL);
    if(in=="END")
        return TokenRecord(END,"END",NULL);
    if(in=="REPEAT")
        return TokenRecord(REPEAT,"REPEAT",NULL);
    if(in=="UNTIL")
        return TokenRecord(UNTIL,"UNTIL",NULL);
    if(in=="READ")
        return TokenRecord(READ,"READ",NULL);
    if(in=="WRITE")
        return TokenRecord(WRITE,"WRITE",NULL);
    isSuccess = false;
    return TokenRecord();
}
bool isNumLetter ( char in )            // Tested [Working]
{
    return ((first_num_in_Ascii<=int(in)&&int(in)<last_num_in_Ascii)||
            (first_cap_in_Ascii<=int(in)&&int(in)<last_cap_in_Ascii)||
            (first_small_in_Ascii<=int(in)&&int(in)<last_small_in_Ascii));
}
TokenRecord getSpecialCharacterToken ( std::string in ) 
{

}