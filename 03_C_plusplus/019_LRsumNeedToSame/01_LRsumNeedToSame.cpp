// c++ code-war
/*
issue description
You are going to be given an array of integers. 
Your job is to take that array and find an index N 
 where the sum of the integers to the left of N is equal to the sum of the integers to the right of N. 
If there is no index that would make this happen, return -1.

For example:

Let's say you are given the array {1,2,3,4,3,2,1}:
Your function will return the index 3, because at the 3rd position of the array, the sum of left side of the index ({1,2,3})
and the sum of the right side of the index ({3,2,1}) both equal 6.

Let's look at another one.
You are given the array {1,100,50,-51,1,1}:
Your function will return the index 1, because at the 1st position of the array, the sum of left side of the index ({1})
and the sum of the right side of the index ({50,-51,1,1}) both equal 1.

Last one:
You are given the array {20,10,-80,10,10,15,35}
At index 0 the left side is {}
The right side is {10,-80,10,10,15,35}
They both are equal to 0 when added. (Empty arrays are equal to 0 in this problem)
Index 0 is the place where the left side and right side are equal.

Note: Please remember that in most programming/scripting languages the index of an array starts at 0.

Input:
An integer array of length 0 < arr < 1000. The numbers in the array can be any integer positive or negative.

Output:
The lowest index N where the side to the left of N is equal to the side to the right of N. 
If you do not find an index that fits these rules, then you will return -1.

Note:
If you are given an array with multiple answers, return the lowest correct index.
*/

#include<iostream>
#include <vector>

using namespace std;

int find_even_index (const vector <int> numbers);

int main()
{
	int numbers1[7] = {1,2,3,4,3,2,1};
	int numbers2[6] = {1,100,50,-51,1,1};
	int numbers3[7] = {20,10,-80,10,10,15,35};

	std::vector<int> v1(numbers1, numbers1 + sizeof numbers1 / sizeof numbers1[0]);
	std::vector<int> v2(numbers2, numbers2 + sizeof numbers2 / sizeof numbers2[0]);
	std::vector<int> v3(numbers3, numbers3 + sizeof numbers3 / sizeof numbers3[0]);
	
	int r1 = find_even_index(v1);
	int r2 = find_even_index(v2);
	int r3 = find_even_index(v3);

	return 0;
}

int find_even_index (const vector <int> numbers) 
{
	int lengthOfData = numbers.size();
	int indicator = 0;

	while(indicator < lengthOfData)
	{
		int sum1 = 0;
		int sum2 = 0;

		for(int i = 0; i<indicator; i++)
		{
			sum1 += numbers[i];
		}

		for(int i = indicator+1; i<lengthOfData; i++)
		{
			sum2 += numbers[i];
		}

		if(sum1 == sum2)
		{
			return indicator;
		}
		else
		{
			indicator++;
		}
	}

	return -1;
}