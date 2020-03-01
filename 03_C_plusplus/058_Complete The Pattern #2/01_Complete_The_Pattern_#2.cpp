// c++ code-war
/*
issue description

Complete The Pattern #2

Description

Task:
You have to write a function pattern which returns the following Pattern (See Pattern & Examples) upto n number of rows.

Note: Returning the pattern is not the same as Printing the pattern.

Rules/Note:
If n < 1 then it should return "" i.e. empty string.
There are no whitespaces in the pattern.
Pattern:
(n)(n-1)(n-2)...4321
(n)(n-1)(n-2)...432
(n)(n-1)(n-2)...43
(n)(n-1)(n-2)...4
...............
..............
(n)(n-1)(n-2)
(n)(n-1)
(n)

Examples:

pattern(4):

4321
432
43
4

pattern(11):

1110987654321
111098765432
11109876543
1110987654
111098765
11109876
1110987
111098
11109
1110
11

Hint: Use \n in string to jump to next line
*/

#include <iostream>
#include <string>

using namespace std;

class Pattern
{
public:
    static string pattern(int number);
};

string Pattern::pattern(int number)
{
	if(number < 1)
	{
		return "";
	}

	string resultPattern = "";
	string* patterningNumber = new string[number];

	int count = 1;

	for(int i = number-1; i >= 0; i--)
	{
		patterningNumber[i] = to_string(count);
		count++;
	}

	for(int i = 0; i < number; i++)
	{
		if(i != 0)
		{
			resultPattern += "\n";
		}

		for(int i = 0; i < count-1; i++)
	    {
			resultPattern += patterningNumber[i];
		}
		count--;
	}

	delete[] patterningNumber;

	return resultPattern;
}

int main()
{
	string r1 = Pattern::pattern(0);
	cout << r1 ;

	return 0;
}
