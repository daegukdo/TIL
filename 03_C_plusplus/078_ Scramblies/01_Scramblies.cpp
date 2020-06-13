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
#include <vector>
#include <utility>

using namespace std;

bool scramble(const std::string& s1, const std::string& s2);

int main() 
{
  bool t1 = scramble("rkqodlw", "world");
	// std::cout << "j";
}

bool scramble(const std::string& s1, const std::string& s2)
{
  vector<pair<char, int>> dataContainer; 
  
  for(int i = 0; i < s2.length(); i++)
  {
    int dataCtnSize = dataContainer.size();
    if(dataCtnSize == 0)
    {
      pair<char, int> tmpPair = make_pair(s2[i], 1);
      dataContainer.push_back(tmpPair);
    }
    else
    {
      for(int j = 0; j < dataCtnSize; j++)
      {
        if(dataContainer[j].first == s2[i])
        {
          dataContainer[j].second++;
        }
        else
        {
          if(j == dataCtnSize - 1)
          {
            pair<char, int> tmpPair = make_pair(s2[i], 1);
            dataContainer.push_back(tmpPair);
          }
        }
      }
    }
  }
  
  for(int i = 0; i < dataContainer.size(); i++)
  {
    cout << dataContainer[i].first;
    cout << dataContainer[i].second;
  }
  
  return true;
}
