// c++ codewar
/*
issue description
Check to see if a string has the same amount of 'x's and 'o's. 
The method must return a boolean and be case insensitive. 
The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

ref. URL : http://www.cplusplus.com/articles/DE18T05o/
*/

#include <algorithm>
bool XO(const std::string& str)
{
  int xCount = std::count(str.begin(), str.end(), 'x') + std::count(str.begin(), str.end(), 'X');
  int oCount = std::count(str.begin(), str.end(), 'o') + std::count(str.begin(), str.end(), 'O');
  return xCount ==  oCount;
}