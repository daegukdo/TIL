// c++ code-war
/*
issue description

Square(n) Sum

Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <vector>

int square_sum(const std::vector<int>& numbers);

int main()
{
	string arr1[] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    vector<string> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	string arr2[] = {"A", "B", ""};
    vector<string> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );


	return 0;
}

int square_sum(const std::vector<int>& numbers)
{
    return -1;
}