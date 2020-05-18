/* 
@ issue description
Simple Pig Latin

Move the first letter of each word to the end of it, then add "ay" to the end of the word. 

Leave punctuation marks untouched.

Examples

pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !

*/

#include<iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string pig_it(string str)
{
  
  string punctuation = "!.,:;?";
  string result = "";
  stringstream ss;
  ss << str;

  for (char ch; ss.get(ch);) { //read char and whitespace
    
    if (isspace(ch))
      result += ch;
        
    else {
      ss.putback(ch); //read a word from the stream
      string word;
      ss >> word;
      
      if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
        word.push_back(word[0]);
        word.erase(word.begin());
        word.push_back('a');
        word.push_back('y');
      }
      result += word;
    }
  }

  return result;
}