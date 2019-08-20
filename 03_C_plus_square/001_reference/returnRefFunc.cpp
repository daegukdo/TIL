// ref : https://modoocode.com/141

#include <iostream>

int fn1(int &a) 
{
	return a;
}

int& fn2(int &a) 
{
	return a;
}

int main()
{
	int x = 1;

	// error! ... fn1 is return 'int' temp. value (not int&)
	// std::cout << fn1(x)++ << std::endl;

	// can check 'x' value has '2'
	std::cout << fn2(x)++ << std::endl;

	return 0;
}