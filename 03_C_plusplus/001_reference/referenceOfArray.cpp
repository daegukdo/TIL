// ref : https://modoocode.com/141

#include <iostream>

int test1() //int main() 
{
	// pointer of reference do not exist!
	// wrong syntax : int& arr[2] = {a, b}; ... arr is pointer of first array
	int arr[3] = {1, 2, 3};
	int (&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;

	return 0;
}