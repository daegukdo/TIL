/* 
@ LeetCode

Design HashMap

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. 
 If the value already exists in the HashMap, update the value.
 
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.

remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

Note:
All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.

ref : https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1140/
*/

#include <iostream>
#include <map>

using namespace std;

class MyHashMap {
private:
    map<int, int> _hashMap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
		auto _iter = _hashMap.find(key);
		if(_iter != _hashMap.end()) { _hashMap.erase(key); }
		_hashMap.insert(pair<int, int>(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto _iter = _hashMap.find(key);
        if(_iter == _hashMap.end()) { return -1; }
        else { return _iter->second; }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        _hashMap.erase(key);
    }
};

int main() {
    MyHashMap hashMap = MyHashMap();

    hashMap.put(1, 1);          
    hashMap.put(2, 2);         
    int r1 = hashMap.get(1);            // returns 1
    int r2 = hashMap.get(3);            // returns -1 (not found)
    cout << r1 << endl;
    cout << r2 << endl;
    
    hashMap.put(2, 1);          // update the existing value
    int r3 = hashMap.get(2);            // returns 1 
    cout << r3 << endl;
    
    hashMap.remove(2);          // remove the mapping for 2
    int r4 = hashMap.get(2);            // returns -1 (not found) 
    cout << r4 << endl;

	return 0;
}
