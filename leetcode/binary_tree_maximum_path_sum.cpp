#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

/*
 Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.  
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
    int maxPathSum(TreeNode* root) {
        
    }
};

void printVector(vector<int> &list){
    for (int i = 0; i < list.size(); ++i)
    {
        cout << list[i] << " ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    /*
      3
   /    \
  5      2
 / \    / \
1   4  6   7
     */
    TreeNode *proot = new TreeNode(3);
    proot->left = new TreeNode(5);
    proot->right = new TreeNode(2);

    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    proot->right->left = new TreeNode(6);
    proot->right->right = new TreeNode(7);

    Solution s;
    cout<< s.sumNumbers(proot) << endl;

    return 0;
}