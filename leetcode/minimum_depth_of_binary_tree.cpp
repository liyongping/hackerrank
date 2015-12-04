#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

For example:
Sample Input

      3
   /    \
  5      2
 / \    / 
1   4  6 

Sample Output

2

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
    /* recusive 
    The solution is almost same with maxDepth, the diff is in leaf node.
    */
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int rDepth = minDepth(root->right)+1;
        int lDepth = minDepth(root->left)+1;

        // if right node is null, we just return the depth for left path
        if(rDepth == 1)
            return lDepth;
        // if left node is null, we just return the depth for right path
        if(lDepth == 1)
            return rDepth;
        
        // both left and right isn't null, return min value.
        return rDepth< lDepth ? rDepth:lDepth;
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

    Solution s;
    cout<<s.minDepth(proot)<<endl;

    return 0;
}