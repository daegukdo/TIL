// c++ code-war
/*
issue description

This time no story, no theory. The examples below show you how to write function accum:

Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z.
*/

#include <iostream>
#include <string>

using namespace std;

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s)
{
	std::string mumblingData = "";

	std::string strData = s;
	int lengthStrData = strData.length();

	for(int i = 0; i<lengthStrData; i++)
	{
		for(int j = 0; j<=i; j++)
		{
			if(j == 0)
			{
				mumblingData += toupper(strData[i]);
			}
			else
			{
				mumblingData += tolower(strData[i]);
			}
		}

		if(i != lengthStrData-1)
		{
			mumblingData += '-';
		}
	}

	return mumblingData;
}

int main()
{
	string t = "ZpglnRxqenU";
	string r = Accumul::accum(t);
	return 0;
}

