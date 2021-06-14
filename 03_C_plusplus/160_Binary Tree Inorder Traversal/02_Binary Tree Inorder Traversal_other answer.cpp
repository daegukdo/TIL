/*
@ LeetCode - Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?

ref : https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1383/
ref : https://smlee729.wordpress.com/2018/03/05/algorithm-%EB%AC%B8%EC%A0%9C-binary-tree-inorder-traversal/
ref : https://javabypatel.blogspot.com/2017/05/binary-tree-inorder-traversal-in-java.html
ref : https://icksw.tistory.com/203
ref : https://xiaqunfeng.gitbooks.io/leetcode/content/tree/94-binary-tree-inorder-traversal.html
ref : http://dblab.duksung.ac.kr/ds/pdf/Chap09.pdf
*/

#include <iostream>  
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (root->left) inorder(root->left, res);
        res.emplace_back(root->val);
        if (root->right) inorder(root->right, res);
    }
};

int main() {
    // ans = 4 6 2 5 1 3
    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);*/

    // ans = 2 1 4 3 5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // ans = 1 2 3
    //TreeNode* root = new TreeNode(3);
    //root->left = new TreeNode(1);
    //root->left->right = new TreeNode(2);

    Solution sol;
    vector<int> rst = sol.inorderTraversal(root);

    return 0;
}
