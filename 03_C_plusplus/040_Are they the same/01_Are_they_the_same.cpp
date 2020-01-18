// c++ code-war
/*
issue description

Are they the "same"?

Given two arrays a and b write a function comp(a, b) (compSame(a, b) in Clojure) that checks whether the two arrays have the "same" elements, with the same multiplicities. 

"Same" means, here, that the elements in b are the elements in a squared, regardless of the order.

Examples
Valid arrays
a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a, b) returns true because in b 121 is the square of 11, 14641 is the square of 121, 20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. 
It gets obvious if we write b's elements in terms of squares:

a = [121, 144, 19, 161, 19, 144, 19, 11] 
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
Invalid arrays
If we change the first number to something else, comp may not return true anymore:

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 132 is not the square of any number of a.

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 36100 is not the square of any number of a.

Remarks
a or b might be [] (all languages except R, Shell). 

a or b might be nil or null or None or nothing (except in Haskell, Elixir, C++, Rust, R, Shell, PureScript).

If a or b are nil (or null or None), the problem doesn't make sense so return false.

If a or b are empty then the result is self-evident.

a or b are empty or not empty lists.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Same 
{
    public:
		static bool comp(vector<int>, vector<int>);
};

bool Same::comp(vector<int> target, vector<int> square)
{
	if(target.empty() || square.empty())
	{
		return false;
	}

	sort(target.begin(), target.end());
	sort(square.begin(), square.end());

	int capacity = target.capacity();

	for(int i = 0; i < capacity; i++)
	{
		if(target[i] == 0 || square[i] == 0)
		{
			return false;
		}

		if(!count(square.begin(),square.end(), target[i] * target[i]))
		{
			return false;
		}

		if(!count(target.begin(), target.end(), (int)sqrt(square[i])))
		{
			return false;
		}
	}

	if(capacity == 0)
	{
		return false;
	}

	return true;
}

int main()
{
	static const int arr1[] = {64, 38, 44, 63, 56, 70, 98, 19, 93, 53, 21, 67, 45, 21, 99, 8, 42};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	static const int arr2[] = {4096, 1444, 1936, 3969, 3136, 4900, 9604, 361, 8649, 2809, 441, 4489, 2025, 441, 9801, 64, 1764};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

	bool r = Same::comp(vec1, vec2);
	return 0;
}