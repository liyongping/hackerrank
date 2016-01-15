#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }

        int left = depthOfTree(root->left);
        int right = depthOfTree(root->right);
        if(abs(left - right) > 1)
            return false;
        else{
            return isBalanced(root->left) &&
                isBalanced(root->right);
        }

        
    }

    int depthOfTree(TreeNode* root){
        if(root == NULL)
            return 0;

        int left = depthOfTree(root->left)+1;
        int right = depthOfTree(root->right)+1;
        return left > right ? left : right;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *proot = new TreeNode(3);
    proot->left = new TreeNode(5);
    //proot->right = new TreeNode(2);

    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    //proot->right->left = new TreeNode(6);
    //proot->right->right = new TreeNode(7);

    Solution s;
    cout<<s.isBalanced(proot)<<endl;

    return 0;
}