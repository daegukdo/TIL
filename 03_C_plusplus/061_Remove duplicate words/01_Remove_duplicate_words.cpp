// c++ code-war
/*
@ issue description

Remove duplicate words

@ Description

Your task is to remove all duplicate words from a string, leaving only single (first) words entries.

Example:

Input:

'alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta'

Output:

'alpha beta gamma delta'
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::string removeDuplicateWords(const string& str);

int main()
{
	string r1 = removeDuplicateWords("my cat is cat fat");

	return 0;
}

std::string removeDuplicateWords(const string& str)
{
	string result = "";

	string inputStr = str;

	istringstream iss(inputStr);

	vector<string> vctStr;

	for(std::string s; iss >> s; )
	{
		if(find(vctStr.begin(), vctStr.end(), s) != vctStr.end())
		{
			// do nothing
		}
		else
		{
			vctStr.push_back(s);
		}
	}

	for(int i = 0; i < vctStr.capacity(); i++)
	{
		if(i != 0)
		{
			result += " ";
		}

		result += vctStr[i];
	}

    return result;
}
