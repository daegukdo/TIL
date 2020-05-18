/* 
@ issue description
Simple Pig Latin

Move the first letter of each word to the end of it, then add "ay" to the end of the word. 

Leave punctuation marks untouched.

Examples

pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !

*/

#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) 
{
	// regular expression
	// https://regexper.com/#%28%5Cw%29%28%5Cw*%29%28%5Cs%7C%24%29
	// \w == word + number + _
	// \w* == (word + number + _) iter.
	// \s == find space
	// a$ == string is end with 'a'
	// () == means group
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}