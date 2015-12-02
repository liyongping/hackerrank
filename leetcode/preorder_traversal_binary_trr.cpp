#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Sample Input

     3
   /   \
  5     2
 / \    / \
1   4  6   7

Sample Output

3 5 1 4 2 6 7


NOTE:
前序遍历：根左右
中序遍历：左根右
后序遍历：左右根 

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
    /*
    Solution 1: recursive
     */
    vector<int> preorderTraversal_recursive(TreeNode* root) {
        vector<int> result;
        preorderTraversal_recursive(root, result);
        return result;

    }

    void preorderTraversal_recursive(TreeNode* root, vector<int> &result){
        if(root == NULL)
            return ;

        result.push_back(root->val);
        preorderTraversal_recursive(root->left, result);
        preorderTraversal_recursive(root->right, result);
    }

    /*
    Solution 2: iterative
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;

        stack<TreeNode*> loopStack;
        TreeNode* curr = root;
        while(curr){

            result.push_back(curr->val);

            if(curr->right)
                loopStack.push(curr->right);

            if(curr->left)
                loopStack.push(curr->left);
            
            if(loopStack.empty()){
                curr = NULL;
                //break;
            }else{
                curr = loopStack.top();
                loopStack.pop();
            }
        }

        return result;
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

    vector<int> result = s.preorderTraversal_recursive(proot);
    for (int i = 0; i < result.size(); ++i)
    {
        cout<<result[i] << " ";
    }
    cout<<endl;

    vector<int> result2 = s.preorderTraversal(proot);
    for (int i = 0; i < result2.size(); ++i)
    {
        cout<<result2[i] << " ";
    }
    cout<<endl;

	return 0;
}