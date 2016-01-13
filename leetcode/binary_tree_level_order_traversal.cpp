#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector< vector<int> > levels;
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        levelOrderTraversal(root, 1);
        return levels;
    }

    void levelOrderTraversal(TreeNode* root, int level) {
        if (root == NULL)
            return;
        if(levels.size() < level){
            vector<int> newlevel;
            levels.push_back(newlevel);
        }
        levels[level-1].push_back(root->val);
        levelOrderTraversal(root->left, level+1);
        levelOrderTraversal(root->right, level+1);

    }
};

int main(int argc, char const *argv[])
{
      /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    
        7    2    

   */
	TreeNode *proot = new TreeNode(5);
    proot->left = new TreeNode(4);
    proot->right = new TreeNode(8);

    proot->left->left = new TreeNode(11);
    proot->left->left->right = new TreeNode(2);
    proot->left->left->left = new TreeNode(7);

    proot->right->left = new TreeNode(13);
    proot->right->right = new TreeNode(4);

    Solution s;

    vector< vector<int> > levelRs = s.levelOrder(proot);
    for(unsigned i = 0; i < levelRs.size(); ++i) {
        vector<int> levelR = levelRs[i];
        for(unsigned j = 0; j < levelR.size(); ++j) {
            cout << levelR[j] << " " ;
        }
        cout<<endl;
    }

	return 0;
}