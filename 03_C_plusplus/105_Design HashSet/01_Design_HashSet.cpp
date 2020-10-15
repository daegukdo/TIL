/* 
@ LeetCode

Design HashSet

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:
add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:
All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.

ref : https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/
*/

#include <iostream>
#include <set>

using namespace std;

class MyHashSet {
private:
	set<int> _hash_set;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
		
    }
    
    void add(int key) {
        _hash_set.insert(key);
    }
    
    void remove(int key) {
        _hash_set.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
		if(_hash_set.find(key) != _hash_set.end()) { return true; }
		else { return false; }
    }
};

int main() {
	MyHashSet hashSet = MyHashSet();

	hashSet.add(1);         
	hashSet.add(2);         
	hashSet.contains(1);    // returns true
	hashSet.contains(3);    // returns false (not found)
	hashSet.add(2);          
	hashSet.contains(2);    // returns true
	hashSet.remove(2);          
	hashSet.contains(2);    // returns false (already removed)

	return 0;
}
