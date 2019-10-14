// c++ code-war
/*
issue description

Complete the method which accepts an array of integers, and returns one of the following:

"yes, ascending" - if the numbers in the array are sorted in an ascending order
"yes, descending" - if the numbers in the array are sorted in a descending order
"no" - otherwise
You can assume the array will always be valid, and there will always be one correct answer.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string is_sorted_and_how(std::vector<int> array);

int main()
{
	int numbers1[5] = {1, 5, 42, 55, 44};

	std::vector<int> v1(numbers1, numbers1 + sizeof numbers1 / sizeof numbers1[0]);

	string a = is_sorted_and_how(v1);

	return 0;
}

std::string is_sorted_and_how(std::vector<int> array)
{
	int arrSize = array.size();

	int asd = 0;
	int dsd = 0;

	for(int i = 0; i < arrSize-1; i++)
	{
		if(array[i] < array[i+1])
		{
			asd++;
		}
		else
		{
			dsd++;
		}
	}

	if((asd != 0) && (dsd != 0))
	{
		return "no";
	}

	if(asd > dsd)
	{
		return "yes, ascending";
	}
	else
	{
		return "yes, descending";
	}
}