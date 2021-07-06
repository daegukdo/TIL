/*
@ LeetCode - Keys and Rooms

There are N rooms and you start in room 0.  

Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  

A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:
Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.

Example 2:
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.

Note:
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.

ref : https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1391/
*/

#include <iostream>  
#include <vector> 

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // pseudo code
        // 방의 개수를 가지는 visited 변수만들기
        // 방을 처음부터 돌면서 key에 따라 visited들을 채워나가기
        // 모든 방을 방문하면 true
        // 그렇지 않으면 false

        return true;
    }
};

int main() {

    return 0;
}
