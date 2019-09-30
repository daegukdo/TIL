// c++ code-war
/*
issue description
Create a function (or write a script in Shell) that takes an integer
as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
*/

#include<iostream>

std::string even_or_odd(int number) 
{
	bool isEven = false;

	if((number%2) == 0)
		isEven = true;

	return isEven ? "Even" : "Odd";
}

int main()
{

	return 0;
}
