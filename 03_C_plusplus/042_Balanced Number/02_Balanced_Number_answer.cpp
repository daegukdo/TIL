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

const char* balancedNum(unsigned long long int n)
{
    auto str = std::to_string(n);
    int balance = 0;
    for (size_t i = 0, j = str.size() / 2 + 1; j < str.size(); ++i, ++j)
    {
        balance += str[i];
        balance -= str[j];
    }
    return (balance == 0)? "Balanced" : "Not Balanced";
}