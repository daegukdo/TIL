/* 
@ LeetCode

Hash Set - Usage
The hash set is one of the implementations of a set which is a data structure to store no repeated values. 

We provide an example of using the hash set in Java, C++ and Python. 

If you are not familiar with the usage of the hash set, it will be helpful to go through the example.

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1130/
*/

#include <iostream>
#include <unordered_set>                // 0. include the library

using namespace std;

int main() {
    // 1. initialize a hash set
    unordered_set<int> hashset;  

    // 2. insert a new key
    hashset.insert(3);
    hashset.insert(2);
    hashset.insert(1);

    // 3. delete a key
    hashset.erase(2);

    // 4. check if the key is in the hash set
    if (hashset.count(2) <= 0) {
        cout << "Key 2 is not in the hash set." << endl;
    }
    hashset.insert(2);
	if (hashset.count(2) == 1) {
        cout << "Key 2 is in the hash set." << endl;
    }

    // 5. get the size of the hash set
    cout << "The size of hash set is: " << hashset.size() << endl; 

    // 6. iterate the hash set
    for (auto it = hashset.begin(); it != hashset.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "are in the hash set." << endl;

    // 7. clear the hash set
    hashset.clear();

    // 8. check if the hash set is empty
    if (hashset.empty()) {
        cout << "hash set is empty now!" << endl;
    }

	return 0;
}
