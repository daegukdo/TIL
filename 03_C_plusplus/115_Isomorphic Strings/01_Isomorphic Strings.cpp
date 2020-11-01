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
private:
	void setUnordered_mapData(string str, unordered_map<char, int> &hashmap){
		for(int i = 0; i < str.length(); i++){
			char tmpChar = str[i];
			if(hashmap.count(tmpChar) == 0){
				hashmap.insert(make_pair(tmpChar, 1));
			}
			else{
				auto search = hashmap.find(tmpChar);
				search->second += 1;
			}
		}
	}
public:
    bool isIsomorphic(string s, string t) {
		unordered_map<char, int> hashmapS;
		unordered_map<char, int> hashmapT;

		setUnordered_mapData(s, hashmapS);
		setUnordered_mapData(t, hashmapT);

		for(int i = 0; i < hashmapS.size(); i++){
			if(hashmapS[s[i]] != hashmapT[t[i]]){
				return false;
			}
		}

        return true;
    }
};

int main() {
	string s = "ab";
	string t = "aa";
	
	Solution sol;

	bool rstIsTrue = sol.isIsomorphic(s, t);

	if(rstIsTrue) { cout << "true!" << endl; }
	else { cout << "no, false!" << endl;; }

	return 0;
}
