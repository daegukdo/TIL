// c++ code-war
/*
issue description

This kata is the first of a sequence of four about "Squared Strings".

You are given a string of n lines, each substring being n characters long: For example:

s = "abcd\nefgh\nijkl\nmnop"

We will study some transformations of this square of strings.

Vertical mirror: vert_mirror (or vertMirror or vert-mirror)
vert_mirror(s) => "dcba\nhgfe\nlkji\nponm"
Horizontal mirror: hor_mirror (or horMirror or hor-mirror)
hor_mirror(s) => "mnop\nijkl\nefgh\nabcd"
or printed:

vertical mirror   |horizontal mirror   
abcd --> dcba     |abcd --> mnop 
efgh     hgfe     |efgh     ijkl 
ijkl     lkji     |ijkl     efgh 
mnop     ponm     |mnop     abcd 
#Task:

Write these two functions
and

high-order function oper(fct, s) where

fct is the function of one variable f to apply to the string s (fct will be one of vertMirror, horMirror)
#Examples:

s = "abcd\nefgh\nijkl\nmnop"
oper(vert_mirror, s) => "dcba\nhgfe\nlkji\nponm"
oper(hor_mirror, s) => "mnop\nijkl\nefgh\nabcd"
Note:
The form of the parameter fct in oper changes according to the language. 
You can see each form according to the language in "Sample Tests".

Bash Note:
The input strings are separated by , instead of \n. 
The ouput strings should be separated by \r instead of \n. See "Sample Tests".

Forthcoming katas will study other tranformations.
*/

#include <iostream>
#include <string>

using namespace std;

class Opstrings
{
public:
    static std::string vertMirror(const std::string &strng)
	{
		char deli = '\n';
		string s = strng;
		string r = "";

		string chunk = "";

		for(int i = 0; i < s.length(); i++)
		{			
			if(s[i] != deli)
			{
				chunk += s[i];
			}
			else
			{
				string temp = "";

				for(int j = chunk.length()-1; j >= 0; j--)
				{
					temp += chunk[j];
				}

				r += temp;
				r += deli;
				chunk = "";
			}
		}

		string temp = "";

		for(int j = chunk.length()-1; j >= 0; j--)
		{
			temp += chunk[j];
		}

		r += temp;
		chunk = "";

		return r;
	}

	static std::string horMirror(const std::string &strng)
	{
		string s = strng;
		string r = "";

		string temp = "";

		for(int i = s.length()-1; i >= 0; i--)
		{
			temp += s[i];
		}

		r = vertMirror(temp);

		return r;
	}
    
	template<typename Func>
    static std::string oper(Func func, const std::string &s)
	{
		return func(s);
	}
};

int main()
{
	string s = "abcd\nefgh\nijkl\nmnop";

	string r1 = Opstrings::oper(Opstrings::vertMirror, s);
	string r2 = Opstrings::oper(Opstrings::horMirror, s);

	return 0;
}