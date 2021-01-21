/* 
@ LeetCode
Find Duplicate Subtrees

Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:
The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200

ref : https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1127/
ref : https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/
ref : https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		// 1,
		// 2,3, 
		// 4,null,2,4, 
		// null,null, 4
		vector<TreeNode*> rst;

		return rst;
    }

	// Function to insert nodes in level order 
	TreeNode* Arr2TreeNodePtr(int arr[], TreeNode* root, int i, int n) { 
		// Base case for recursion 
		if (i < n) { 
			TreeNode* temp = new TreeNode(arr[i]); 
			root = temp; 
  
			// insert left child 
			root->left = Arr2TreeNodePtr(arr, root->left, 2 * i + 1, n); 
  
			// insert right child 
			root->right = Arr2TreeNodePtr(arr, root->right, 2 * i + 2, n); 
		} 
		return root; 
	} 
};

int main() {
	const int arrLength = 10;
	int nums[arrLength] = {1,2,3,4,NULL,2,4,NULL,NULL,4};
	
	TreeNode *tn = new TreeNode();

	Solution sol;

	TreeNode* root = sol.Arr2TreeNodePtr(nums, tn, 0, arrLength);
	vector<TreeNode*> rst = sol.findDuplicateSubtrees(root);

	return 0;
}
