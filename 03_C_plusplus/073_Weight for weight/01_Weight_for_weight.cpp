// c++ code-war
/*
@ issue description

Weight for weight

@ Description

My friend John and I are members of the "Fat to Fit Club (FFC)". 

John is worried because each month a list with the weights of members is published and each month he is the last on the list which means he is the heaviest.

I am the one who establishes the list so I told him: "Don't worry any more, I will modify the order of the list". 

It was decided to attribute a "weight" to numbers. The weight of a number will be from now on the sum of its digits.

For example 99 will have "weight" 18, 100 will have "weight" 1 so in the list 100 will come before 99. 

Given a string with the weights of FFC members in normal order can you give this string ordered by "weights" of these numbers?

Example:
"56 65 74 100 99 68 86 180 90" ordered by numbers weights becomes: "100 180 90 56 65 74 68 86 99"

When two numbers have the same "weight", let us class them as if they were strings (alphabetical ordering) and not numbers: 100 is before 180 because its "weight" (1) is less than the one of 180 (9) and 180 is before 90 since, having the same "weight" (9), it comes before as a string.

All numbers in the list are positive numbers and the list can be empty.

Notes
it may happen that the input string have leading, trailing whitespaces and more than a unique whitespace between two consecutive numbers
Don't modify the input
For C: The result is freed.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
};

std::string WeightSort::orderWeight(const std::string &strng)
{
	char spliter = ' ';
	std::string sortedWeightStr = "";

	// split by " "
	// vector int list for origin int value

	vector<int> weightVect;
    weightVect.clear();
	
    size_t initialPos = 0;
	size_t pos = strng.find( spliter );

    while( pos != std::string::npos )
	{
		// except case : "111 12 132 "
		pos = strng.find( spliter, initialPos );

        weightVect.push_back( stoi(strng.substr( initialPos, pos - initialPos )) );
        initialPos = pos + 1;
    }

	// vector int list for each digits summation

	vector<int> weightOrdering;
	vector<int> weightOrderingSorted;
	weightOrdering.clear();
	weightOrderingSorted.clear();

	int weightVectSize = weightVect.size();
	int sumOfDigits = 0;
	int tmpNum = 0;

	for(int i = 0; i < weightVectSize; i++)
	{
		sumOfDigits = 0;
		tmpNum = weightVect[i];
		while (tmpNum != 0) 
		{ 
			sumOfDigits += tmpNum % 10;
			tmpNum = tmpNum / 10; 
		}
		weightOrdering.push_back(sumOfDigits);
		weightOrderingSorted.push_back(sumOfDigits);
	}

	sort(weightOrderingSorted.begin(), weightOrderingSorted.end());

	// sorting with index

	for(int i = 0; i < weightVectSize; i++)
	{
		for(int j = 0; j < weightVectSize; j++)
		{
			if(weightOrderingSorted[i] == )
		}
	}

	return sortedWeightStr;
}

int main()
{
	std::string r1 = WeightSort::orderWeight("111 12 132");
	return 0;
}