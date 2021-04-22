/*
@ LeetCode - Open the Lock

You have a lock in front of you with 4 circular wheels.

Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.

The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.

Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
 the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock,
 return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1

Constraints:
1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.

We can think of this problem as a shortest path problem on a graph: there are `10000` nodes (strings `'0000'` to `'9999'`),
 and there is an edge between two nodes if they differ in one digit, that digit differs by 1 (wrapping around, so `'0'` and `'9'` differ by 1),
 and if *both* nodes are not in `deadends`.

ref : https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1375/
ref : https://lenchen.medium.com/leetcode-752-open-the-lock-297b1b14f135
*/

#include <iostream>  
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // target에 가는 모든 방법 찾기 (오름차순, 내림차순)

        int step = 0;

        string startDigits = "0000";

        queue<string> q;
        q.push(startDigits);
        int qSize = 1;
        set<string> set;

        while (!q.empty()) {
            for (int i = 0; i < qSize; i++)
            {
                string current = q.front();
                q.pop();

                if (find(deadends.begin(), deadends.end(), current) == deadends.end()) {
                    if (current == target) {
                        return step;
                    }

                    deadends.push_back(current);

                    for (int digit = 0; digit < 4; digit++) {
                        int digitUpDown[2] = { (int(current[digit] - '0') + 1) % 10 , (int(current[digit] - '0') + 9) % 10 };
                        string tmpCurrent = current;
                        for (int& d : digitUpDown) {
                            for (int j = 0; j < 4; j++) {
                                if (j == digit) {
                                    int tmp = d;
                                    tmpCurrent[j] = char(tmp + '0');
                                    if (set.find(tmpCurrent) == set.end()) {
                                        q.push(tmpCurrent);
                                        set.insert(tmpCurrent);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            qSize = q.size();
            step++;
        }

        return -1;
    }
};

int main() {
    vector<string> deadends = { "7867","6676","8687","7886","6768","8877","6767","6676","6666","7876",
        "6688","6677","6877","7786","6778","6868","6868","7867","7668","7666","8868","7887","6788","7687",
        "7788","7877","6867","6867","7876","8787","8878","6668","6878","6766","8667","8688","6788","7687",
        "8887","8766","6867","8867","7866","7866","6686","7776","8687","7888","6777","6678","6678","6686",
        "6677","7886","6876","8666","6667","7768","7688","7668","6786","7766","7867","8866","7887","6676",
        "8776","6867","8888","6678","8687","6868","7888","8666","6678","6668","7678","7667","8786","8768",
        "6766","8776","8677","7788","7868","7878","6786","6678","6876","7667","8866","8666","8768","8886",
        "8787","8688","8766","8867","7886","6876","7776","7867","8668","7777","8888","7767","8778","8888",
        "6876","8777","7877","8866","8668","8878","7678","8787","7788","8887","8667","7887","6686","8778",
        "7768","8787","7677","6768","7877","7788","7768","6768","6786","7887","7768","6676","6777","8686",
        "7867","8788","8887","8776","7677","8786","8678","7666","8776","7676","6767","8776","8888","8766",
        "8876","7777","7677","6767","7878","7868","8677","7677","8788","6667","8866","8887","6686","6777",
        "6676","8787","6788","8866","6767","8676","8868","8768","8888","7866","7877","7768","7686","7888",
        "6666","6887","6787","7667","6676","8666","8886","8878","8678","8868","8888","8867","7878","7787",
        "8776","7877","6788","8778","6768","8677","8678","6778","7888","6866","6768","6666","6887","8866",
        "7676","7866","7876","7678","7686","8887","7676","6788","8787","6666","8866","6876","8676","8688",
        "8887","7887","7777","8887","8688","6668","6686","6887","7677","6867","6786","6877","7788","6667",
        "8778","8786","8767","7778","8867","8877","6668","8886","7888","7767","7666","8678","8668","8767",
        "7666","6787","6886","8787","6886","8768","8767","8676","6767","8776","8768","8687","8778","7888",
        "6768","7878","6668","7688","6687","7866","8878","6877","7667","8886","7876","6667","8877","7666",
        "7668","7676","6888","6686","7666","7688","7666","6678","6676","7678","8788","7667","7767","8766",
        "6867","8767","8676","8786","8667","6678","6778","8877","8788","6866","7687","6876","8878","8866",
        "6788","6877","8768","8778","8778","8866","7866","7887","7878","8766","8778","7868","8787","6676",
        "8668","7866","8787","8767","6876","8867","6688","6886","6668","6878","7866","8678","8867","7667",
        "7878","8778","8777","7866","8878","7868","6876","7688","7677","7678","7777","8888","8776","8688",
        "6878","8877","7678","7777","7878","6678","6688","6868","8876","6668","8877","8786","6688","8766",
        "8887","6678","8886","8876","8888","8878","6786","7686","7867","7767","7888","8866","6876","7767",
        "6687","6687","6688","6868","8668","6886","8686","7766","8777","8667","8886","7676","7768","6788",
        "8688","7676","7686","8777","7886","7788","6666","7687","6676","6777","6866","6767","7787","7877",
        "6777","6886","7877","7787","7787","8768","7787","8778","6766","7677","6788","6786","6767","8687",
        "6687","8668","6876","6666","7676","8667","6688","6766","6677","7667","8668","8866","7686","8866",
        "8687","8866","8768","7886","6877","8877","6676","6887","6788","8877","8887","8886","8887","6676",
        "8867","6867","7768","8868","6668","7878","7887","8768","6876","7787","7876","8886","6778","7778",
        "7687","6686","7787","8767","8668","7686","7678","8788","6687","8666","7877","6668","7686","6866",
        "6888","8786","7778","7786","8787","6777","6867","7787","7777","6766","8666","6778","6867","8668",
        "8667","7678","8668","7677","8787","6876","6668","7788","7688","7687","8778","8787","8688","8867" };
    string target = "6776";

    Solution s;
    int rst = s.openLock(deadends, target);

    return 0;
}