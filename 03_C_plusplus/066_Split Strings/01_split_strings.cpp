// c++ code-war
/*
@ issue description

Split Strings

@ Description

Complete the solution so that it splits the string into pairs of two characters. 

If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

Examples:

solution("abc") // should return {"ab", "c_"}
solution("abcdef") // should return {"ab", "cd", "ef"}
*/

#include <string>
#include <vector>

using namespace std;

std::vector<std::string> solution(const std::string &s);

int main()
{

	return 0;
}

std::vector<std::string> solution(const std::string &s)
{
	int strLength = s.length();

	std::vector<std::string> result;

	if(strLength % 2 == 0)
	{
		// even case
		int splitCount = strLength / 2;
		int tmp = 2;
		for(int i = 0; i < splitCount; i++)
		{
			std::string sTmp = "";
			sTmp += s[tmp * i];
			sTmp += s[tmp * i + 1];
			result.push_back(sTmp);
		}
	}
	else
	{
		// odd case
		int splitCount = strLength / 2 + 1;
		int tmp = 2;
		for(int i = 0; i < splitCount; i++)
		{
			std::string sTmp = "";
			if(i < splitCount - 1)
			{
				sTmp += s[tmp * i];
				sTmp += s[tmp * i + 1];
			}
			else
			{
				sTmp += s[tmp * i];
				sTmp += "_";
			}
			result.push_back(sTmp);
		}
	}

    return result;
}