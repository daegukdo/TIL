/* 
@ LeetCode
- Introduction to 2D Array

Similar to a one-dimensional array, a two-dimensional array also consists of a sequence of elements. 
But the elements can be laid out in a rectangular grid rather than a line.

- Principle

In some languages, 
the multidimensional array is actually implemented internally as a one-dimensional array while in some other languages, 
there is actually no multidimensional array at all.
C++ stores the two-dimensional array as a one-dimensional array.
The picture below shows the actual structure of a M * N array A:
So actually A[i][j] equals to A[i * N + j] if we defined A as a one-dimensional array which also contains M * N elements.

- Dynamic 2D Array

Similar to the one-dimensional dynamic array, we can also define a dynamic two-dimensional array. 
Actually, it can be just a nested dynamic array. You can try it out by yourself.

ref : https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1166/
*/

#include <iostream>

using namespace std;

template <size_t n, size_t m>
void printArray(int (&a)[n][m]) 
{
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < m; ++j) 
		{
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
	cout << "Example I:" << endl;
    int a[2][5];
    printArray(a);

    cout << "Example II:" << endl;
    int b[2][5] = {{1, 2, 3}};
    printArray(b);

    cout << "Example III:"<< endl;
    int c[][5] = {1, 2, 3, 4, 5, 6, 7};
    printArray(c);

    cout << "Example IV:" << endl;
    int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
    printArray(d);

	return 0;
}
