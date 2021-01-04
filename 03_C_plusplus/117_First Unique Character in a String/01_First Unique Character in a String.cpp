/*
@ LeetCode
First Unique Character in a String

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 
Note: You may assume the string contains only lowercase English letters.

ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1120/
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {		
		unordered_map<char, pair<int, int>> map;

		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			auto item = map.find(c);
			if(item != map.end()){
				item->second.second++;
			}
			else{
				map.insert(make_pair(c, make_pair(i, 1)));
			}
		}

		int rslInt = INT_MAX;

		for(auto iter = map.begin(); iter != map.end(); iter++){
			if(iter->second.second == 1){
				if(rslInt > iter->second.first){
					rslInt = iter->second.first;
				}
			}
		}

		if(rslInt == INT_MAX){
			return -1;
		}
		else{
			return rslInt;
		}
    }
};

int main() {	
	string str = "leetcode";

	Solution sol;

	int rstInt = sol.firstUniqChar(str);
	
	return 0;
}
