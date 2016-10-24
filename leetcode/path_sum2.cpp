#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
 Given a binary tree and a sum, 
 find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector< vector<int> > sumv;
public:
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dsf(root, sum, 0, path);
        return sumv;
    }

    void dsf(TreeNode* root, int sum, int currsum, vector<int> path){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(root->val + currsum == sum){
                path.push_back(root->val);
                sumv.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        dsf(root->left, sum, currsum+root->val, path);
        dsf(root->right, sum, currsum+root->val, path);
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

    
    vector< vector<int> > paths = s.pathSum(proot, 22);
    for(unsigned i = 0; i < paths.size(); ++i) {
        vector<int> xx = paths[i];
        for(unsigned j = 0; j < xx.size(); ++j) {
            cout<< xx[j] << " ";
        }
        cout << endl;
    }

	return 0;
}