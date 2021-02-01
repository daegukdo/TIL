/* 
@ LeetCode
Insert Delete GetRandom O(1)

Implement the RandomizedSet class:
 - bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
 - bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
 - int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
 Each element must have the same probability of being returned.

Follow up: Could you implement the functions of the class with each function works in average O(1) time?

Example 1:
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 
Constraints:
-231 <= val <= 231 - 1
At most 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

ref : https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1141/
ref : https://www.cplusplus.com/reference/unordered_map/unordered_map/erase/
ref : https://www.cplusplus.com/reference/cstdlib/rand/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdlib.h>       /* srand, rand */
#include <time.h>         /* time */

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
	unordered_map<int, int> map;
	vector<int> vct;

    RandomizedSet() {
        map.clear();
		vct.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto elm = map.find(val);
		if(elm == map.end()){
			map.insert(make_pair(val, 1));
			vct.push_back(val);
			return true;
		}
		else{
			return false;
		}
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto elm = map.find(val);
		if(elm == map.end()){
			return false;
		}
		else{
			map.erase(val);
			vct.erase(find(vct.begin(), vct.end(), val));
			return true;
		}
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        srand (time(NULL));
        int ranNumInVct = rand() % vct.size();
		return vct[ranNumInVct];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
	RandomizedSet randomizedSet;
	randomizedSet.insert(1); 
	randomizedSet.insert(10); 
	randomizedSet.insert(20); 
	randomizedSet.insert(30); 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 
	cout << randomizedSet.getRandom() << endl; 

	return 0;
}
