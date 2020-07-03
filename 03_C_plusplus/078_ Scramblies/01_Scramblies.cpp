/* 
@ issue description
Scramblies

Complete the function scramble(str1, str2)
that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered

Input strings s1 and s2 are null terminated.

Examples

scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool scramble(const std::string& s1, const std::string& s2);

int main() 
{
  bool t1 = scramble("rkqodlw", "world");
  bool t2 = scramble("cedewaraaossoqqyt", "codewars");
  
  if(t2 == true)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  return 0;
}

bool scramble(const std::string& s1, const std::string& s2)
{
	int ansCount = s2.length();
	int tstCount = 0;

	string refStr = s2;
	string trgStr = s1;

	sort (refStr.begin(), refStr.end());
	sort (trgStr.begin(), trgStr.end());

	int enumRefChar = 0;
	int enumTrgChar = 0;

	while(enumRefChar < refStr.length())
	{
		char refChar = refStr[enumRefChar];
		int refNumOfChar = 0;

		for(int i = enumRefChar; i < refStr.length(); i++)
		{
			if(refChar == refStr[i])
			{
				refNumOfChar++;
			}
		}

		enumRefChar = enumRefChar + refNumOfChar;

		int trgNumOfChar = 0;

		for(int i = enumTrgChar; i < trgStr.length(); i++)
		{
			if(refChar == trgStr[i])
			{
				trgNumOfChar++;
			}

			if(trgNumOfChar >= refNumOfChar)
			{
				enumTrgChar = i;
				break;
			}
			
			if((trgNumOfChar < refNumOfChar) && ((trgStr[i] - '0') > (refChar - '0')))
			{
				return false;
			}
		}
	}

	return true;
}
