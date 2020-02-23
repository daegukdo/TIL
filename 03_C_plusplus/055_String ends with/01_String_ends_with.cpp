// c++ code-war
/*
issue description

String ends with?

Description
Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false
*/

#include <string>

using namespace std;

bool solution(std::string const &str, std::string const &ending);

int main()
{
	bool r1 = solution("abc ", "c ");

	return 0;
}

bool solution(std::string const &str, std::string const &ending)
{
	int numOfStr = str.length() - 1;
	int numOfEnding = ending.length() - 1;

	if(numOfEnding == -1)
	{
		return true;
	}

	char tmp;
	int checker = 0;

	for(int i = numOfEnding; i >= 0; i--)
	{
		tmp = ending[i];
		
		if(str[numOfStr - checker] == tmp)
		{
			checker++;
		}
		else
		{
			return false;
		}
	}

    return true;
}