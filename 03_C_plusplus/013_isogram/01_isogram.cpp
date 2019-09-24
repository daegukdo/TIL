/*
issue description
An isogram is a word that has no repeating letters, consecutive or non-consecutive. 
Implement a function that determines whether a string that contains only letters is an isogram. 
Assume the empty string is an isogram. 
Ignore letter case.

example : 
isIsogram "Dermatoglyphics" == true
isIsogram "moose" == false
isIsogram "aba" == false
*/

#include <iostream>

using namespace std;


bool isIsogram(string text);

int main()
{
	string txt1 = "Dermatoglyphics";
	string txt2 = "moose";
	string txt3 = "aba";

	bool r1 = isIsogram(txt1);
	bool r2 = isIsogram(txt2);
	bool r3 = isIsogram(txt3);

	return 0;
}

bool isIsogram(string text)
{
	bool result = true;
	char temp;

	int textLength = text.length();

	for(int i = 0; i<textLength; i++)
	{
		int sameCounter = 0;
		temp = text[i];

		for(int j = 0; j<textLength; j++)
		{
			if(temp == text[j])
			{
				sameCounter++;

				if(sameCounter > 1)
				{
					result = false;
					break;
				}
			}
		}
	}

	return result;
}

