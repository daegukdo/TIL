/* 
@ issue description
Simple Pig Latin

Move the first letter of each word to the end of it, then add "ay" to the end of the word. 

Leave punctuation marks untouched.

Examples

pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string pig_it(string str);

int main() 
{
	string r1 = pig_it("Hello world !");

	std::cout << "j" + '\n';

	return 0;
}

string pig_it(string str)
{
	string outputSentence = "";

	string punctuationMarksStrs = "!?.,\"\';:-+<>()* ";
	string surffixStr = "ay";
	char splitChar = ' ';

	vector<string> wordsVect;
	string tmpWordStr = "";

	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == splitChar)
		{
			wordsVect.push_back(tmpWordStr);
			tmpWordStr = "";
		}
		else if(i == str.length() - 1)
		{
			tmpWordStr += str[i];
			wordsVect.push_back(tmpWordStr);
			tmpWordStr = "";
		}
		else
		{
			tmpWordStr += str[i];
		}
	}

	for(int i = 0; i < wordsVect.size(); i++)
	{
		tmpWordStr = "";
		for(int j = 0; j < wordsVect[i].length(); j++)
		{
			if(j != 0)
			{
			    tmpWordStr += wordsVect[i][j];
			}
			
			if(j == wordsVect[i].length() - 1)
			{
				tmpWordStr += wordsVect[i][0];
			}
		}

		wordsVect[i] = tmpWordStr;

		if(wordsVect[i].length() == 1)
		{
			if (punctuationMarksStrs.find(wordsVect[i]) != std::string::npos)
			{
				// find
			}
			else
			{
				wordsVect[i] = wordsVect[i] + surffixStr;
			}
		}
		else
		{
			wordsVect[i] = wordsVect[i] + surffixStr;
		}
	}

	for(int i = 0; i < wordsVect.size(); i++)
	{
		outputSentence += wordsVect[i];
		if(i != wordsVect.size() - 1)
		{
			outputSentence += ' ';
		}
	}

    return outputSentence;
}
