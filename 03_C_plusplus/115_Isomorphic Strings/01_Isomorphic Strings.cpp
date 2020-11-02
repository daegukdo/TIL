/* 
@ LeetCode
Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.
Example 1:
Input: s = "egg", t = "add"
Output: true
Example 2:
Input: s = "foo", t = "bar"
Output: false
Example 3:
Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1117/
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		unordered_map<char, char> hashmapST;
		unordered_map<char, char> hashmapTS;

		string compStr = "";
		
		for(int i = 0; i < s.length(); i++){
			char tmpCharS = s[i];
			char tmpCharT = t[i];
			if(hashmapST.count(tmpCharS) == 0){
				hashmapST.insert(make_pair(tmpCharS, tmpCharT));
				compStr += tmpCharT;
			}
			else{
				auto search = hashmapST.find(tmpCharS);
				compStr += search->second;
			}

			if(hashmapTS.count(tmpCharT) == 0){
				hashmapTS.insert(make_pair(tmpCharT, tmpCharS));
			}

			if(hashmapST.size() != hashmapTS.size()){ return false; }
		}

		if(compStr != t){ return false; }

		return true;
    }
};

int main() {
	string s = "aba";
	string t = "baa";
	
	Solution sol;

	bool rstIsTrue = sol.isIsomorphic(s, t);

	if(rstIsTrue) { cout << "true!" << endl; }
	else { cout << "no, false!" << endl;; }

	return 0;
}
