/* 
@ LeetCode

Introduction to Array

An array is a basic data structure to store a collection of elements sequentially. 

But elements can be accessed randomly since each element in the array can be identified by an array index.

An array can have one or more dimensions. 

Here we start with the one-dimensional array, which is also called the linear array. Here is an example:

In the above example, there are 6 elements in array A. 

That is to say, the length of A is 6. We can use A[0] to represent the first element in the array. 

Therefore, A[0] = 6. Similarly, A[1] = 3, A[2] = 8 and so on.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	// 1. Initialize
	// make array that have 5 elements with all element will be set as the random value
	int a0[5];
	// make array that have 5 elements with some element will be set as the default(=0) value
	int a1[5] = {1, 2, 3};

	// 2. Get Length
	int a0size = sizeof(a0) / sizeof(*a0);
	int a1size = sizeof(a1) / sizeof(*a1);
	cout << "The size of a0 is: " << a0size << endl;
	cout << "The size of a1 is: " << a1size << endl;

	// 3. Access Element
    cout << "The first element of a0 is: " << a0[0] << endl;
    cout << "The first element of a1 is: " << a1[0] << endl;

	// 4. Iterate all Elements
	// method 1
    cout << "[Version 1] The contents of a1 are:";
    for (int i = 0; i < a1size; ++i) 
	{
        cout << " " << a1[i];
    }
    cout << endl;
	
	// method 2
	cout << "[Version 2] The contents of a1 are:";
    for (int& item: a1)
	{
        cout << " " << item;
    }
    cout << endl;

	// 5. Modify Element
    a1[0] = 4;
	cout << "check modified value:";
    for (int i = 0; i < a1size; ++i) 
	{
        cout << " " << a1[i];
    }
    cout << endl;

	// 6. Sort
    sort(a1, a1 + a1size);
	cout << "check sorted value:";
    for (int i = 0; i < a1size; ++i) 
	{
        cout << " " << a1[i];
    }
    cout << endl;

	return 0;
}
