// c++ code-war
/*
@ issue description

Rot13

@ Description

ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. 

ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. 

If there are numbers or special characters included in the string, 
they should be returned as they are. 

Only letters from the latin/english alphabet should be shifted, 
like in the original Rot13 "implementation".
*/

#include <string>
using namespace std;

string rot13(string msg);

int main()
{
	string r = rot13("test");

	return 0;
}

string rot13(string msg)
{
	// a = 97, z = 122
	// A = 65, Z = 90

	int msgLength = msg.length();

	char* charArray = new char[msgLength];

	for(int i = 0; i < msgLength; i++)
	{
		charArray[i] = msg[i];
	}

	int charIntTmp = 0;

	for(int i = 0; i < msgLength; i++)
	{
		charIntTmp = charArray[i] - 0;

		// upper case
		if((charIntTmp <= 90) && (charIntTmp >= 65))
		{
			charIntTmp = charIntTmp + 13;
			if(charIntTmp > 90)
			{
				charArray[i] = char(65 + charIntTmp - 90 - 1);
			}
			else
			{
				charArray[i] = char(charIntTmp);
			}
		}
		// lower case
		else if((charIntTmp <= 122) && (charIntTmp >= 97))
		{
			charIntTmp = charIntTmp + 13;
			if(charIntTmp > 122)
			{
				charArray[i] = char(97 + charIntTmp - 122 - 1);
			}
			else
			{
				charArray[i] = char(charIntTmp);
			}
		}
	}

	string result = "";

	for(int i = 0; i < msgLength; i++)
	{
		result = result + charArray[i];
	}	

	delete[] charArray;

	return result;
}