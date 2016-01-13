#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
 Given a binary tree and a sum, 
 determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && root->val == sum)
            return true;
        return hasPathSum(root->left, sum-root->val) ||
               hasPathSum(root->right, sum-root->val);
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