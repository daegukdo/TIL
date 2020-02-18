// c++ code-war
/*
issue description

Balanced Number (Special Numbers Series #1 )

Definition
Balanced number is the number that * The sum of all digits to the left of the middle digit(s) and the sum of all digits to the right of the middle digit(s) are equal*.

Task
Given a number, Find if it is Balanced or not .

Notes
If the number has an odd number of digits then there is only one middle digit, e.g. 92645 has middle digit 6; 
otherwise, there are two middle digits , e.g. 1301 has middle digits 3 and 0

The middle digit(s) should not be considered when determining whether a number is balanced or not, 
e.g 413023 is a balanced number because the left sum and right sum are both 5.

Number passed is always Positive .

Return the result as String

Input >> Output Examples
balancedNum (7) ==> return "Balanced"
Explanation:
Since , The sum of all digits to the left of the middle digit (0)

and the sum of all digits to the right of the middle digit (0) are equal , then It's Balanced

balancedNum (295591) ==> return "Not Balanced"
Explanation:
Since , The sum of all digits to the left of the middle digits (11)

and the sum of all digits to the right of the middle digits (10) are Not equal , then It's Not Balanced

Note : The middle digit(s) are 55 .

balancedNum (959) ==> return "Balanced"
Explanation:
Since , The sum of all digits to the left of the middle digits (9)

and the sum of all digits to the right of the middle digits (9) are equal , then It's Balanced

Note : The middle digit is 5 .

balancedNum (27102983) ==> return "Not Balanced"
Explanation:
Since , The sum of all digits to the left of the middle digits (10)

and the sum of all digits to the right of the middle digits (20) are Not equal , then It's Not Balanced

Note : The middle digit(s) are 02 .


*/

#include <iostream>
#include <string>

using namespace std;

string balancedNum (unsigned long long int number);

int main()
{
	string a0 = balancedNum(7);
	string a1 = balancedNum(959);
	string a2 = balancedNum(13);
	string a3 = balancedNum(432);
	string a4 = balancedNum(424);
	string a5 = balancedNum(1024);
	string a6 = balancedNum(66545);
	string a7 = balancedNum(295591);
	string a8 = balancedNum(1230987);
	string a9 = balancedNum(56239814);

	return 0;
}

string balancedNum (unsigned long long int number)
{
	// long int to string
	string numStr = to_string(number);

	// length of string
	int lengthOfNumStr = numStr.length();

	// define variable
	int leftSum = 0;
	int rightSum = 0;

	if((lengthOfNumStr % 2 == 1))
	{
		// if string length is odd

		// length / 2 = middle index ... start at 0
		int middleIndex = lengthOfNumStr / 2;

		// sum of 0 to middle-1 vs. sum of middle+1 to end
		for(int i = 0; i < middleIndex; i++)
		{
			leftSum = leftSum + ((int)numStr[i] - '0');
		}

		for(int i = lengthOfNumStr-1; i > middleIndex; i--)
		{
			rightSum = rightSum + ((int)numStr[i] - '0');
		}
	}
	else
	{
		// if string length is even

		// length / 2 = right middle index ... start at 0
		int rightMiddleIndex = lengthOfNumStr / 2;

		// length / 2 - 1 = left middle index ... start at 0
		int leftMiddleIndex = lengthOfNumStr / 2 - 1;

		// sum of 0 to left  middle-1 vs. sum of right middle+1 to end
		for(int i = 0; i < leftMiddleIndex; i++)
		{
			leftSum = leftSum + ((int)numStr[i] - '0');
		}

		for(int i = lengthOfNumStr-1; i > rightMiddleIndex; i--)
		{
			rightSum = rightSum + ((int)numStr[i] - '0');
		}
	}

	if(leftSum == rightSum)
	{
		return "Balanced";
	}
	else
	{
		return "Not Balanced";
	}
}