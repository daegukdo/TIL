// c++ code-war
/*
issue description

Introduction
Digital Cypher assigns to each letter of the alphabet unique number. For example:

 a  b  c  d  e  f  g  h  i  j  k  l  m
 1  2  3  4  5  6  7  8  9 10 11 12 13
 n  o  p  q  r  s  t  u  v  w  x  y  z
14 15 16 17 18 19 20 21 22 23 24 25 26
Instead of letters in encrypted word we write the corresponding number, eg. The word scout:

 s  c  o  u  t
19  3 15 21 20
Then we add to each obtained digit consecutive digits from the key. For example. In case of key equal to 1939 :

   s  c  o  u  t
  19  3 15 21 20
 + 1  9  3  9  1
 ---------------
  20 12 18 30 21

   m  a  s  t  e  r  p  i  e  c  e
  13  1 19 20  5 18 16  9  5  3  5
+  1  9  3  9  1  9  3  9  1  9  3
  --------------------------------
  14 10 22 29  6 27 19 18  6  12 8
Task
Write a function that accepts str string and key number and returns an array of integers representing encoded str.

Input / Output
The str input string consists of lowercase characters only.
The key input number is a positive integer.

Example
Encode("scout",1939);  ==>  [ 20, 12, 18, 30, 21]
Encode("masterpiece",1939);  ==>  [ 14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Kata
{
public:
    static std::vector<int> Encode(std::string str, int n);
};

std::vector<int> Kata::Encode(std::string str, int n)
{
	string testans = "";

	string strStr = str;
	int strLength = strStr.length();

	int *encoded = new int[strLength];
	
	string nStr = std::to_string(n);
	int nStrOrder = nStr.length();

	int nCount = 0;

	char strChar;
	int strCharRaw = 0;

	for(int i = 0; i<strLength; i++)
	{
		strChar = strStr[i];
		strCharRaw = strChar - 96;

		int a = (int)(nStr[nCount]) - 48;

		if(nCount <= nStrOrder-1)
		{
			encoded[i] = strCharRaw + (int)(nStr[nCount]) - 48;
			nCount++;
		}
		else
		{
			nCount = 0;
			encoded[i] = strCharRaw + (int)(nStr[nCount]) - 48;
			nCount++;
		}

		testans += std::to_string(encoded[i]);
	}
	
	std::vector<int> encoded_result(encoded, encoded + strLength);

	delete[] encoded;

	return encoded_result;
}

int main()
{
	std::vector<int> v1 = Kata::Encode("scout",1939);
	std::vector<int> v2 = Kata::Encode("masterpiece",1939);

	for(int i = 0; i < 11; i++)
	{
		cout << v2[i] << endl;
	}

	return 0;
}