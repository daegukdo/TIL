// c++ code-war
/*
issue description

Find The Parity Outlier

You are given an array (which will have a length of at least 3, but could be very large) containing integers. 

The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 

Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
*/

#include <vector>

int FindOutlier(std::vector<int> arr)
{
    int even;
    int odd;
  
    int evenCount = 0;
    int oddCount = 0;
  
    for (auto a : arr)
        a % 2 == 0 ? (evenCount++, even = a) : (oddCount++, odd = a);
  
    return evenCount < oddCount ? even : odd;
}