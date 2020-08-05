/* 
@ LeetCode

Introduction to String

A string is actually an array of unicode characters. 

You can perform almost all the operations we used in an array. 

You can try it out by yourself.

However, there are some differences. 

In this article, we will go through some of them which you should be aware of when dealing with a string. 

These features might vary a lot from one language to another. 

ref : https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1158/
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	////
	// define
	string s1 = "Hello World";

    cout << "s1 is \"Hello World\"" << endl;
    string s2 = s1;
    cout << "s2 is initialized by s1" << endl;
    string s3(s1);
    cout << "s3 is initialized by s1" << endl;

	////
	// Compare Function

    // compare by '=='
    cout << "Compared by '==':" << endl;
    cout << "s1 and \"Hello World\": " << (s1 == "Hello World") << endl;
    cout << "s1 and s2: " << (s1 == s2) << endl;
    cout << "s1 and s3: " << (s1 == s3) << endl;

    // compare by 'compare'
    cout << "Compared by 'compare':" << endl;
    cout << "s1 and \"Hello World\": " << !s1.compare("Hello World") << endl;
    cout << "s1 and s2: " << !s1.compare(s2) << endl;
    cout << "s1 and s3: " << !s1.compare(s3) << endl;

	////
	// Immutable or Mutable

	s1[5] = ',';
    cout << s1 << endl;

	////
	// Extra Operations

    // 1. concatenate
    s1 += "!";
    cout << s1 << endl;
    // 2. find
    cout << "The position of first 'o' is: " << s1.find('o') << endl;
    cout << "The position of last 'o' is: " << s1.rfind('o') << endl;
    // 3. get substr
    cout << s1.substr(6, 5) << endl;

	return 0;
}
