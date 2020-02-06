// c++ code-war
/*
issue description

Jumping Number (Special Numbers Series #4)

Definition
Jumping number is the number that All adjacent digits in it differ by 1.

Task
Given a number, Find if it is Jumping or not .

Notes
Number passed is always Positive .

Return the result as String .

The difference between ¡®9¡¯ and ¡®0¡¯ is not considered as 1 .

All single digit numbers are considered as Jumping numbers.

Input >> Output Examples
jumpingNumber(9) ==> return "Jumping!!"

Explanation:
It's single-digit number
jumpingNumber(79) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(23) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1
jumpingNumber(556847) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(4343456) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1
jumpingNumber(89098) ==> return "Not!!"

Explanation:
Adjacent digits don't differ by 1
jumpingNumber(32) ==> return "Jumping!!"

Explanation:
Adjacent digits differ by 1
*/

#include <iostream>
#include <string>

using namespace std; 

string jumpingNumber(int number);

int main()
{
	string a1 = jumpingNumber(6);
	string a2 = jumpingNumber(66);
	string a3 = jumpingNumber(654);
	string a4 = jumpingNumber(154);

	return 0;
}

string jumpingNumber(int number)
{
	string numStr = to_string(number);

	int lengthStr = numStr.length();

	int tmp1 = 0;
	int tmp2 = 0;

	for(int i = 0; i < lengthStr-1; i++)
	{
		tmp1 = numStr[i] - '0';
		tmp2 = numStr[i+1] - '0';

		if((abs(tmp1 - tmp2) > 1) || (abs(tmp1 - tmp2) == 0))
		{
			return "Not!!";
		}
	}

	if(lengthStr == 0)
	{
		return "Jumping!!";
	}

	return "Jumping!!";
}