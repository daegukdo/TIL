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
#include <utility>
#include <algorithm>

using namespace std;

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
};

std::string WeightSort::orderWeight(const std::string &strng)
{
	std::string sortedWeightStr = "";

	vector<pair<long long, string>> weightVect;
    weightVect.clear();

	string tmpWeightStr = "";
	bool isMakeData = false;
	long long pos = 0;
	long long strngLength = strng.length();
	long long tmpWeight = 0;
	long long tmpWeightDigitsSum = 0;

	if(strngLength == 0)
	{
		return sortedWeightStr;
	}

    while( pos != strngLength )
	{
		isMakeData = true;
		tmpWeightStr = "";

		while(isMakeData)
		{
			if(pos == strngLength)
			{
				break;
			}

			if(strng[pos] == ' ')
			{
				if(tmpWeightStr != "")
				{
					isMakeData = false;
				}
			}
			else
			{
				tmpWeightStr += strng[pos];
			}
			pos++;
		}

		if(tmpWeightStr != "")
		{
			tmpWeightDigitsSum = 0;

			tmpWeight = stoll(tmpWeightStr);
			while (tmpWeight != 0) 
			{ 
				tmpWeightDigitsSum += tmpWeight % 10;
				tmpWeight = tmpWeight / 10; 
			}

			weightVect.push_back( make_pair(tmpWeightDigitsSum, tmpWeightStr));
		}
    }

	sort(weightVect.begin(), weightVect.end());

	long long weightVectSize = weightVect.size();

	for(long long i = 0; i < weightVectSize; i++)
	{
		sortedWeightStr += weightVect[i].second;
		if(i < weightVectSize - 1)
		{
			sortedWeightStr += " ";
		}
	}

	return sortedWeightStr;
}

int main()
{
	std::string r1 = WeightSort::orderWeight("1111111111112 11");
	return 0;
}