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
	string r = rot13("test");

	return 0;
}

std::string rot13(std::string msg) {
  for (char& c : msg) {
    switch (c) {
      case 'A'...'M': case 'a'...'m': c += 13; break;
      case 'N'...'Z': case 'n'...'z': c -= 13; break;
    }
  }
  return msg;
}