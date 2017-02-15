#ifndef H_CalcInterp
#define H_CalcInterp

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

enum CALCTOKENS {

	EOFSY = 0, //End of file
	ID, //ID
	NUMCONST, //number constant

	READYSY, //read keyword

	WRITESY, //write keyword

	ASSIGNSY, //assignment symbol 

	LPAREN, //left parenthesis

	RPAREN, //right parenthesis

	ADDOP, //addition sign

	MINOP, //minus sign

	MULTOP, //multiplication sign 

	DIVOP, //division sign 
};



map<CALCTOKENS, string> TOKENMAP;


void setupMap () 
{
	TOKENMAP[EOFSY] = "EOFSY";
	TOKENMAP[ID] = "ID";
	TOKENMAP[NUMCONST] = "NUMCONST";
	TOKENMAP[READYSY] = "READYSY";
	TOKENMAP[WRITESY] = "WRITESY";
	TOKENMAP[ASSIGNSY] = "ASSIGNSY";
	TOKENMAP[LPAREN] = "LPAREN";
	TOKENMAP[RPAREN] = "RPAREN";
	TOKENMAP[ADDOP] = "ADDOP";
	TOKENMAP[MINOP] = "MINOP";
	TOKENMAP[MULTOP] = "MULTOP";
	TOKENMAP[DIVOP] = "DIVOP";
};

struct Token 
{

	CALCTOKENS TokenNum;
	string TokenString;
};


bool iequals(const string a, const string b)
{
    unsigned int s = a.size();

    if (b.size() != s)
        return false;

    for (unsigned int i = 0; i < s; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;

    return true;
}



//checks that input is valid

bool isDouble( string myString ) 
{
    istringstream iss(myString);
    double s;
    iss >> noskipws >> s;
    return (iss.eof() && !iss.fail()); 
}



#endif