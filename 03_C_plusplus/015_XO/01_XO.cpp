// c++ codewar
/*
issue description
Check to see if a string has the same amount of 'x's and 'o's. 
The method must return a boolean and be case insensitive. 
The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

ref. URL : http://www.cplusplus.com/articles/DE18T05o/
*/

#include <string>
#include <iostream>
#include <locale>

bool XO(const std::string& str);

int main()
{
	std::string a= "xXoxo";

	bool r1 = XO(a);

	return 0;
}

bool XO(const std::string& str)
{
	std::locale loc;

	bool result = false;

	char Xdeli = 'X';
	char Oceli = 'O';

	int Xcount = 0;
	int Ocount = 0;

	int count = str.length();

	for(int i = 0; i<count; i++)
	{
		if(Xdeli == std::toupper(str[i], loc))
		{
			Xcount++;
		}

		if(Oceli == std::toupper(str[i], loc))
		{
			Ocount++;
		}
	}

	if(Xcount == Ocount)
	{
		result = true;
	}

	return result;
}