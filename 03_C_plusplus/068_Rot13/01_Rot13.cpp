// c++ code-war
/*
@ issue description

Rot13

@ Description

ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. 

ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. 

If there are numbers or special characters included in the string, 
they should be returned as they are. 

Only letters from the latin/english alphabet should be shifted, 
like in the original Rot13 "implementation".
*/

#include <string>
using namespace std;

string rot13(string msg);

int main()
{
	string r = rot13("A");

	return 0;
}

string rot13(string msg)
{
	// a = 97, z = 122
	// A = 65, Z = 90

	char t = msg[0];

	char t1 = t + 13;
	char t2 = t1 + 12;

	int t_int = t - 0;

	return "";
}