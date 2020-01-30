// c++ code-war
/*
issue description

Square(n) Sum

Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.
*/

#include <vector>

using namespace std;

int square_sum(const std::vector<int>& numbers);

int main()
{
	int arr1[] = {1, 2};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	int arr2[] = {0, 3, 4, 5};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );


	return 0;
}

int square_sum(const std::vector<int>& numbers)
{
    int ret=0;
    for (auto x:numbers) ret+=(x*x);
    return ret;
}