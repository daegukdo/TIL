// c++ code-war
/*
issue description

Compare Strings by Sum of Chars

ompare two strings by comparing the sum of their values (ASCII character code).

For comparing treat all letters as UpperCase
null/NULL/Nil/None should be treated as empty strings
If the string contains other characters than letters, treat the whole string as it would be empty
Your method should return true, if the strings are equal and false if they are not equal.

Examples:
"AD", "BC"  -> equal
"AD", "DD"  -> not equal
"gf", "FG"  -> equal
"zz1", ""   -> equal (both are considered empty)
"ZzZz", "ffPFF" -> equal
"kl", "lz"  -> not equal
null, ""    -> equal
*/

#include <string>

using namespace std;

bool compare(std::string s1, std::string s2);

int main()
{
	bool a = compare(NULL, "");

	return 0;
}

bool compare(std::string s1, std::string s2)
{
	// 비어있는 스트링 값 변환 : null/NULL/Nil/None
	// 스트링 값 - char로 분해 - ASCII 변환 (모든 스트링 값을 하나씩) - summation
	// s1과 s2 비교
	// bool 값 return

	if(s1.empty() || s2.empty())
	{
		return true;
	}

	int charSumS1 = 0;
	int charSumS2 = 0;

	int capaS1 = s1.length();
	int capaS2 = s2.length();
	
	if(capaS1 != 0)
	{
		for(int i = 0; i < capaS1; i++)
		{
			charSumS1 += toupper(s1[i]);
		}
	}

	if(capaS2 != 0)
	{
		for(int i = 0; i < capaS2; i++)
		{
			charSumS2 += toupper(s2[i]);
		}
	}

	if(charSumS1 == charSumS2)
	{
		return true;
	}
	else
	{
		return false;
	}
}