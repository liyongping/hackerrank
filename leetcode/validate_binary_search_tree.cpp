#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <limits.h>
using namespace std;

/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

For example:
Sample Input

      3
   /    \
  5      2
 / \    / \
1   4  6   7

Sample Output

3

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long minV, long maxV) {
        if(root == NULL)
            return true;
        return minV < root->val && root->val < maxV &&
            isValidBST(root->left, minV, root->val) &&
            isValidBST(root->right, root->val, maxV);
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *proot = new TreeNode(3);
    proot->left = new TreeNode(4);
    proot->right = new TreeNode(2);

    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    proot->right->left = new TreeNode(6);
    proot->right->right = new TreeNode(7);

    Solution s;
    cout<<s.isValidBST(proot)<<endl;

    return 0;
}