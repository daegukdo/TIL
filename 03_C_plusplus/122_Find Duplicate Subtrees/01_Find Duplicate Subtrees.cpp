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
		// 1, 2,3, 4,null, 2,4, null,null, 4
		vector<TreeNode*> rst;

		return rst;
    }

	TreeNode* arr2TreeNodePtr(int* nums){
		TreeNode tn;
		int aa = nums[8];
		for(int i = 0; i < sizeof(nums); i++){
			auto a = nums[i];
			int b = a;
		}

		return &tn;
	}
};

int main() {
	int nums[10] = {1,2,3,4,NULL,2,4,NULL,NULL,4};

	//TreeNode root(1);
	//root.left = new TreeNode(2);
	//root.right = new TreeNode(3);
	//root.left->left = new TreeNode(4);
	//if(root.left->right == NULL)
	//{
	//	string a = "d";
	//}

	Solution sol;

	TreeNode* root = sol.arr2TreeNodePtr(nums);
	vector<TreeNode*> rst = sol.findDuplicateSubtrees(root);

	return 0;
}
