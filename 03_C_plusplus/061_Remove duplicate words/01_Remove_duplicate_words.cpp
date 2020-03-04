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

	string tmpStr = "";
	int trgIdx = 0;
	int spaceIdx = 0;


	
	spaceIdx = inputStr.find(" ");

	if(spaceIdx != -1)
	{
		for(int i = 0; i < spaceIdx; i++)
		{
			tmpStr += inputStr[i];
		}

		trgIdx = inputStr.find(tmpStr);

		while(trgIdx != -1)
		{
			inputStr.erase(trgIdx, tmpStr.length());

			trgIdx = inputStr.find(tmpStr);
		}
	}

    return result;
}