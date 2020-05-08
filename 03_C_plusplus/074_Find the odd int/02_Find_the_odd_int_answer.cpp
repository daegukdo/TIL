// c++ code-war
/*
@ issue description

Find the odd int

@ Description

Given an array, find the integer that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
*/

#include <vector>
#include <utility>

using namespace std;

int findOdd(const std::vector<int>& numbers);

int main()
{
	int arr1[] = { 1, 2, 2, 3, 3 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    vector<int> v1(arr1, arr1 + n1); 

	int r1 = findOdd(v1);

	return 0;
}

int findOdd(const std::vector<int>& numbers){
  for (auto elem: numbers){
    if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
      return elem;
    }
  }
  return 0;
}