// c++ code-war
/*
issue description

Two Sum

Write a function that takes an array of numbers (integers for the tests) and a target number. 

It should find two different items in the array that, when added together, give the target value. 

The indices of these items should then be returned in a tuple like so: (index1, index2).

For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

The input will always be valid 

(numbers will be an array of length 2 or greater, and all of the items will be numbers; 

target will always be the sum of two different items from that array).

Based on: http://oj.leetcode.com/problems/two-sum/

twoSum [1, 2, 3] 4 === (0, 2)
twoSum [1234, 5678, 9012], 14690 === (1, 2)
twoSum [2, 2, 3] 4 === (0, 1)
*/

#include <string>
#include <vector>

using namespace std;

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target);

int main()
{
	int arr1[] = {1, 2, 3};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	int trg1 = 4;

	std::pair<std::size_t, std::size_t> r1 = two_sum(vec1, trg1);

	return 0;
}

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target)
{
	// 두 숫자의 합
	// 첫번째 숫자와 다른 숫자들 중 하나의 합을 비교
	// 두번째 숫자와 다른 숫자들 중 하나의 합을 비교 (이때 첫번째 숫자는 빠진다)
	// 세번째 숫자와 다른 숫자들 중 하나의 합을 비교 (이때 첫번째, 두번째 숫자는 빠진다)

	int twoSumData[] = {0, 0};
	int vecCapa = numbers.capacity();

	for(int i = 0; i < vecCapa; i++)
	{
		for(int j = 0; j < vecCapa; j++)
		{
			if(j > i)
			{
				if(target == (numbers[i] + numbers[j]))
				{
					twoSumData[0] = i;
					twoSumData[1] = j;
					break;
				}
			}
		}
	}

	std::pair<std::size_t, std::size_t> result = make_pair(twoSumData[0], twoSumData[1]);

    return result;
}