// c++ code-war
/*
issue description

Compare Strings by Sum of Chars

ompare two strings by comparing the sum of their values (ASCII character code).

For comparing treat all letters as UpperCase
null/NULL/Nil/None should be treated as empty strings
If the string contains other characters than letters, treat the whole string as it would be empty
Your method should return true, if the strings are equal and false if they are not equal.

Examples:
"AD", "BC"  -> equal
"AD", "DD"  -> not equal
"gf", "FG"  -> equal
"zz1", ""   -> equal (both are considered empty)
"ZzZz", "ffPFF" -> equal
"kl", "lz"  -> not equal
null, ""    -> equal
*/

#include <string>

using namespace std;

bool compare(std::string s1, std::string s2);

int main()
{
	bool a = compare(NULL, "");

	return 0;
}

bool compare(std::string s1, std::string s2)
{
    // Returning true for possible empty strings
    if (s1.empty() || s2.empty())
      return true;
      
    int sumString1 = 0, sumString2 = 0;
    for (int i = 0; i < s1.length(); ++i) {
        
        if (!isalpha(s1.at(i))) {
            return true;
        }
        
        sumString1 += toupper(s1.at(i));
    }
    
    for (int i = 0; i < s2.length(); ++i) {
     
        if (!isalpha(s2.at(i)))
            return true;
        
        sumString2 += toupper(s2.at(i));
    }
      
    return sumString1 == sumString2;
}