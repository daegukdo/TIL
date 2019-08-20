// ref : https://modoocode.com/141

#include <iostream>

// pointer *p
int change_val_like_c(int *p);

// using reference
int change_val_using_ref(int &p);

void pointer_vs_reference();

int test() //int main() 
{

	int n1 = 5;
	std::cout << n1 << std::endl;
	// reference &number
	// int *p = number address
	// & operator send value ... &n1 send value (not address!)
	change_val_like_c(&n1);
	std::cout << n1 << std::endl;

	int n2 = 5;
	std::cout << n2 << std::endl;
	// reference &number
	// int &p = number
	change_val_using_ref(n2);
	std::cout << n2 << std::endl;

	// test with break point
	void pointer_vs_reference();

	return 0;
}

// *p see input value address 
int change_val_like_c(int *p) 
{
	*p = 3;
	return 0;
}

// &p is another name of input value
int change_val_using_ref(int &p)
{
	p = 3;
	
	return 0;
}

void pointer_vs_reference()
{
	int number = 10;

	// another name of 'number' value
	int& ref = number;

	// p see 'number' value address
	int* p = &number;

	// 'number' value add 1 
	// ref = number = 11
	ref++;

	// 'number' value address add 1 (4 byte) ... int = 4 byte
	// p = other address, number = 10
	p++;
}