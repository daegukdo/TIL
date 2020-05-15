/* 
@ issue description
Stop gninnipS My sdroW!

Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata).

Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

Examples: 

spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" 
spinWords( "This is a test") => returns "This is a test" 
spinWords( "This is another test" )=> returns "This is rehtona test"
*/

#include <iostream>
#include <string>

using namespace std;

std::string spinWords(const std::string &str);
std::string spinWord(std::string input, int reverseInt);

int main() 
{
  string r1 = spinWords("Hey fellow warriors");
	std::cout << r1 + "\n";
}

std::string spinWords(const std::string &str)
{
  string results = "";
  string tmpStr = "";
  
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] == ' ')
    {
      results += spinWord(tmpStr, 5);
      results += ' ';
      
      tmpStr = "";
    }
    else
    {
      tmpStr += str[i];
    }
    
    if(i == str.length() - 1)
    {
      results += spinWord(tmpStr, 5);
    }
  }
  
  return results;
}

std::string spinWord(std::string input, int reverseInt)
{
  std::string resultWord = "";
  
  if(input.length() >= reverseInt)
  {
    for(int j = input.length() - 1; j > -1; j--)
    {
      resultWord += input[j];
    }
  }
  else
  {
    resultWord += input;
  }
  
  return resultWord;
}
