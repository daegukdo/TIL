// c++ code-war
/*
issue description

Fun with trees: max sum

You are given a binary tree. Implement the method maxSum which returns the maximal sum of a route from root to leaf. 

For example, given the following tree:

    17
   /  \
  3   -10
 /    /  \
2    16   1
         /
        13
The method should return 23, since [17,-10,16] is the route from root to leaf with the maximal sum.

The class TreeNode is available for you:

class TreeNode
{
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
    ...
};
This kata is part of fun with trees series:

Fun with trees: max sum
Fun with trees: array to tree
Fun with trees: is perfect
*/

#include <iostream>

using namespace std;

class TreeNode
{
public:
	TreeNode* left;
	TreeNode* right;
	int value;

	TreeNode(int vl = 0)
	{
		value = vl;
		left = NULL;
		right = NULL;
	}

	static TreeNode* leaf(int vl)
	{
		TreeNode* _leaf = new TreeNode();

		_leaf->value = vl;
		return _leaf;
	}

	TreeNode* withLeaves(int lf, int rt)
	{
		left = new  TreeNode();
		right = new  TreeNode();

		left->value = lf;
		right->value = rt;
		return this;
	}

	static TreeNode* join(int vl, TreeNode* lf, TreeNode* rt)
	{
		TreeNode* _join = new TreeNode();

		_join->value = vl;
		_join->left = lf;
		_join->right = rt;
		return _join;
	}
};

class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
        if (root == nullptr)
        {
          return 0;
        }
        auto r = maxSum(root->right) + root->value;
        auto l = maxSum(root->left) + root->value;
        return std::max(r, l);
    }
};

int main()
{
	TreeNode* left = TreeNode::leaf(-22)->withLeaves(9, 50);
    TreeNode* right = TreeNode::leaf(11)->withLeaves(9, 2);
    TreeNode* root = TreeNode::join(5, left, right);
	
	int r1 = Solution::maxSum(root);

	return 0;
}

