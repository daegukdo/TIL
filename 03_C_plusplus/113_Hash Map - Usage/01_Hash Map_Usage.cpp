/* 
@ LeetCode
Hash Map - Usage

The hash map is one of the implementations of a map which is used to store (key, value) pairs.

We provide an example of using the hash map in Java, C++ and Python.

If you are not familiar with the usage of the hash map, it will be helpful to go through the example.

ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1129/
*/

#include <iostream>
#include <unordered_map>                // 0. include the library

using namespace std;

int main() {
    // 1. initialize a hash map
    unordered_map<int, int> hashmap;

    // 2. insert a new (key, value) pair
    hashmap.insert(make_pair(0, 0));
    hashmap.insert(make_pair(2, 3));

    // 3. insert a new (key, value) pair or update the value of existed key
    hashmap[1] = 1;
    hashmap[1] = 2;

    // 4. get the value of a specific key
    cout << "The value of key 1 is: " << hashmap[1] << endl;

    // 5. delete a key
    hashmap.erase(2);

    // 6. check if a key is in the hash map
    if (hashmap.count(2) <= 0) {
        cout << "Key 2 is not in the hash map." << endl;
    }

    // 7. get the size of the hash map
    cout << "the size of hash map is: " << hashmap.size() << endl; 

    // 8. iterate the hash map
    for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << "are in the hash map." << endl;

    // 9. clear the hash map
    hashmap.clear();

    // 10. check if the hash map is empty
    if (hashmap.empty()) {
        cout << "hash map is empty now!" << endl;
    }

	return 0;
}
