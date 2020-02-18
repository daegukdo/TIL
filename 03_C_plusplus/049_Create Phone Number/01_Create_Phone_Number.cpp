// c++ code-war
/*
issue description

Create Phone Number

Write a function that accepts an array of 10 integers (between 0 and 9), 
that returns a string of those numbers in the form of a phone number.

Example:
createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"
The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses!
*/

#include <string>

using namespace std;

std::string createPhoneNumber(const int arr [10]);

int main()
{
	int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	string a = createPhoneNumber(arr1);

	return 0;
}

std::string createPhoneNumber(const int arr [10])
{
	string arrStr[10];

	for(int i = 0; i < 10; i++)
	{
		arrStr[i] = std::to_string(arr[i]);
	}

	string firstPnStr = "";
	string secondPnStr = "";
	string thirdPnStr = "";

	for(int i = 0; i < 3; i++)
	{
		firstPnStr += arrStr[i];
	}

	for(int i = 3; i < 6; i++)
	{
		secondPnStr += arrStr[i];
	}

	for(int i = 6; i < 10; i++)
	{
		thirdPnStr += arrStr[i];
	}

	return "(" + firstPnStr + ") " + secondPnStr + "-" + thirdPnStr;
}