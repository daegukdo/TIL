// c++ code-war
/*
@ issue description

Split Strings

@ Description

Complete the solution so that it splits the string into pairs of two characters. 

If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

Examples:

solution("abc") // should return {"ab", "c_"}
solution("abcdef") // should return {"ab", "cd", "ef"}
*/

#include <string>
#include <vector>

using namespace std;

std::vector<std::string> solution(const std::string &s);

int main()
{

	return 0;
}

std::vector<std::string> solution(const std::string &s) {
    std::vector <std::string> res;
    for (int i = 0; i < s.length(); i += 2) res.push_back(s.substr(i, 2));
    if (s.length() % 2) res[res.size() - 1] += "_";
    return res;
}