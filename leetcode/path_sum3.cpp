#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11


      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

Return 3. The paths that sum to 13 ares:

 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        return dsf(root, sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
    
    int dsf(TreeNode* root, int sum){
        int rt = 0;
        if(root == NULL)
            return rt;
        if(root->val == sum)
            rt ++;
        rt += dsf(root->left, sum - root->val);
        rt += dsf(root->right, sum - root->val);
        return rt;
    }
};


int main(int argc, char const *argv[])
{
	TreeNode *proot = new TreeNode(5);
    proot->left = new TreeNode(4);
    proot->right = new TreeNode(8);

    proot->left->left = new TreeNode(11);
    proot->left->left->right = new TreeNode(2);
    proot->left->left->left = new TreeNode(7);

    proot->right->left = new TreeNode(13);
    proot->right->right = new TreeNode(4);

    Solution s;

    
    cout<<s.hasPathSum(proot,100) << endl;
    cout<<s.hasPathSum(proot,22) << endl;

	return 0;
}