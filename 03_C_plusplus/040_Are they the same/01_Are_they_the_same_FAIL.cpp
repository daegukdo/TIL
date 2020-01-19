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

using namespace std;

class Same 
{
    public:
		static bool comp(vector<int>, vector<int>);

	private:
		static bool compareEachElements(vector<int> target, vector<int> square);
};

bool Same::comp(vector<int> target, vector<int> square)
{
	int capacityTarget = target.capacity();
	int capacitySquare = square.capacity();

	if(target.empty() || square.empty())
	{
		return false;
	}

	if((capacityTarget == 0) || (capacitySquare == 0))
	{
		return false;
	}
	
	sort(target.begin(), target.end());
    sort(square.begin(), square.end());

	vector<int> targetSquare;

	for(int i = 0; i < capacityTarget; i++)
	{
		if(target[i] == 0 || square[i] == 0)
		{
			return false;
		}

		targetSquare.push_back(target[i] * target[i]);
	}

	if(Same::compareEachElements(targetSquare, square))
	{
		if(Same::compareEachElements(square, targetSquare))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Same::compareEachElements(vector<int> target, vector<int> square)
{
	int capacityTarget = target.capacity();
	int capacitySquare = square.capacity();

	if(capacityTarget != capacitySquare)
	{
		return false;
	}

	for(int i = 0; i < capacityTarget; i++)
	{
		if(!count(square.begin(),square.end(), target[i]))
		{
			return false;
		}
		else
		{
			for(int j = 0; j < capacitySquare; j++)
			{
				if(square[j] == target[i])
				{
					square.erase(square.begin()+j, square.begin()+j+1);
					break;
				}
			}
		}
	}

	return true;
}

int main()
{
	static const int arr1[] = {1, 2, 3, 3};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	static const int arr2[] = {1, 4, 9, 4};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

	bool r = Same::comp(vec1, vec2);
	return 0;
}