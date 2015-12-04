#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.

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
    /* recusive */
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int rDepth = maxDepth(root->right)+1;
        int lDepth = maxDepth(root->left)+1;
        
        return rDepth> lDepth ? rDepth:lDepth;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *proot = new TreeNode(3);
    proot->left = new TreeNode(5);
    proot->right = new TreeNode(2);

    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    proot->right->left = new TreeNode(6);
    proot->right->right = new TreeNode(7);

    Solution s;
    cout<<s.maxDepth(proot)<<endl;

    return 0;
}