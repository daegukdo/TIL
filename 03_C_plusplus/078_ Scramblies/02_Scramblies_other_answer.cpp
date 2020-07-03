/* 
@ issue description
Scramblies

Complete the function scramble(str1, str2)
that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered

Input strings s1 and s2 are null terminated.

Examples

scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool scramble(const std::string& s1, const std::string& s2);

int main() 
{
  bool t1 = scramble("rkqodlw", "world");
  bool t2 = scramble("cedewaraaossoqqyt", "codewars");
  
  if(t2 == true)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  return 0;
}

bool scramble(std::string s1, std::string s2) {
  std::sort(begin(s1), end(s1));
  std::sort(begin(s2), end(s2));
  return std::includes(begin(s1), end(s1), begin(s2), end(s2));
}