/* 
@ LeetCode

Jewels and Stones

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. 
Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
 
Constraints:
1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.

ref : https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1136/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 각 변수들을 순서대로 정렬
        // 이후 jewels의 요소들을 map에 저장 ... 이때 대소문자는 구분, 중복은 없애기
        // jewels의 가장 큰 char를 변수에 저장
        // stones의 값을 하나하나 꺼내어 jewels의 요소가 있는 map에서찾고 개수를 저장
        
        int rst = 0;
        
        string sorted_jewels = jewels;
        string sorted_stones = stones;
        sort(begin(sorted_jewels), end(sorted_jewels));
        sort(begin(sorted_stones), end(sorted_stones));
        
        unordered_map<char, int> map_jewels;
        char last_jewels;
        
        for(auto iter = sorted_jewels.begin(); iter != sorted_jewels.end(); iter++){
            char tmpChar = *iter;
            auto tmpElm = map_jewels.find(tmpChar);
            if(tmpElm == map_jewels.end()){
                map_jewels.insert(make_pair(tmpChar, 0));
            }
            last_jewels = tmpChar;
        }
        
        for(auto iter = sorted_stones.begin(); iter != sorted_stones.end(); iter++){
            char tmpChar = *iter;
            if(last_jewels < tmpChar){
                break;
            }
            auto tmpElm = map_jewels.find(tmpChar);
            if(tmpElm != map_jewels.end()){
                tmpElm->second += 1;
            }
        }
        
        for(auto iter = map_jewels.begin(); iter != map_jewels.end(); iter++){
            rst += iter->second;
        }
        
        return rst;
    }
};

int main() {
	string jewels = "aA";
	string stones = "aAAbBBb";
	
	Solution sol;

	int rst = sol.numJewelsInStones(jewels, stones);
	
	cout << rst << endl;

	return 0;
}
