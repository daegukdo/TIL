/* 
@ LeetCode

Find Duplicates By Hash Set

As we know, it is easy and effective to insert a new value and check if a value is in a hash set or not.

Therefore, typically, a hash set is used to check if a value has ever appeared or not.

An Example

Let's look at an example:

Given an array of integers, find if the array contains any duplicates. 

This is a typical problem which can be solved by a hash set.

You can simply iterate each value and insert the value into the set. 

If a value has already been in the hash set, there is a duplicate.

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1102/
*/

#include <iostream>
#include <vector>
#include <unordered_set>                // 0. include the library

using namespace std;

bool findDuplicates(vector<int>& keys) {
    // Replace Type with actual type of your key
    unordered_set<int> hashset;
    for (int key : keys) {
        if (hashset.count(key) > 0) {
            return true;
        }
        hashset.insert(key);
    }
    return false;
}

int main() {
	// not Duplicates
	int numsArr1[7] = {1,2,3,4,5,6,7};
    vector<int> nums1(numsArr1, *(&numsArr1 + 1));

	if(findDuplicates(nums1)){
		cout << "nums1 vector container has Duplicates element." << endl;
	}
	else{
		cout << "nums1 vector container has not Duplicates element." << endl;
	}

	// Duplicates
	int numsArr2[7] = {1,2,3,4,5,7,7};
    vector<int> nums2(numsArr2, *(&numsArr2 + 1));

	if(findDuplicates(nums2)){
		cout << "nums2 vector container has Duplicates element." << endl;
	}
	else{
		cout << "nums2 vector container has not Duplicates element." << endl;
	}

	return 0;
}
