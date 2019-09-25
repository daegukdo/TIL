// c++ codewar
/*
issue description
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. 
No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.
*/

#include <vector>

using namespace std;


long sumTwoSmallestNumbers(vector<int> numbers);

int main()
{
	int numbers1[5] = {19, 5, 42, 2, 77};
	int numbers2[4] = {10, 343445353, 3453445, 3453545353453};

	std::vector<int> v1(numbers1, numbers1 + sizeof numbers1 / sizeof numbers1[0]);
	long r1 = sumTwoSmallestNumbers(v1);

	std::vector<int> v2(numbers2, numbers2 + sizeof numbers2 / sizeof numbers2[0]);
	long r2 = sumTwoSmallestNumbers(v2);

	return 0;
}

long sumTwoSmallestNumbers(vector<int> numbers)
{
	int count = numbers.size();

	long twoSum = 0;

	for(int i =0; i<count; i++)
	{
		int isSmall = 0;

		for(int j=0; j<count; j++)
		{
			if(numbers[i] < numbers[j])
			{
				isSmall++;
			}
		}

		int rank = (count - isSmall);

		if((rank == 1) || (rank == 2))
		{
			twoSum += numbers[i];
		}
	}

	return twoSum;
}

