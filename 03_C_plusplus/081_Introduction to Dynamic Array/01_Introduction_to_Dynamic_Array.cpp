/* 
@ LeetCode

Introduction to Dynamic Array

As we mentioned in the previous article, an array has a fixed capacity and we need to specify the size of the array when we initialize it. 

Sometimes this will be somewhat inconvenient and wasteful.

Therefore, most programming languages offer built-in dynamic array which is still a random access list data structure but with variable size. 

For example, we have vector in C++ and ArrayList in Java.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	// 1. initialize
	// vector container need to vector header file
    vector<int> v0;
	// five elements set 0
    vector<int> v1(5, 0);

	// 2. make a copy
	// copy v1 to v2
    vector<int> v2(v1.begin(), v1.end());
	// copy v2 to v3
    vector<int> v3(v2);

	// 2. cast an array to a vector
    int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1));

	// 3. get length
    cout << "The size of v4 is: " << v4.size() << endl;

	// 4. access element
    cout << "The first element in v4 is: " << v4[0] << endl;

	// 5. iterate the vector
	// using for loop with index
    cout << "[Version 1] The contents of v4 are:";
    for (int i = 0; i < v4.size(); ++i) 
	{
        cout << " " << v4[i];
    }
    cout << endl;

	// using for loop with item
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) 
	{
        cout << " " << item;
    }
    cout << endl;

	// using for loop with item and iterator
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) 
	{
        cout << " " << *item;
    }
    cout << endl;

	// 6. modify element
    v4[0] = 5;

    // 7. sort
	// need to algorithm header file
    sort(v4.begin(), v4.end());

    // 8. add new element at the end of the vector
	// add '-1' to v4 vector container 
    v4.push_back(-1);

    // 9. delete the last element
    v4.pop_back();

	return 0;
}
