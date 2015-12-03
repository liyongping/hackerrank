#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Sample Input

      3
   /    \
  5      2
 / \    / \
1   4  6   7

Sample Output

1 4 5 6 7 2 3


根右左:
3 2 7 6 5 4 1 ,再置反


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
    vector<int> postorderTraversal_recursive(TreeNode* root) {
        vector<int> result;
        postorderTraversal_recursive(root, result);
        return result;

    }
    // postorder: left right root
    void postorderTraversal_recursive(TreeNode* root, vector<int> &result){
        if(root == NULL)
            return ;

        postorderTraversal_recursive(root->left, result);
        postorderTraversal_recursive(root->right, result);
        result.push_back(root->val);
    }

    /*
    Solution 2: iterative, 后序遍历：左右根 , 入栈顺序，应该是 root right left
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;

        stack<TreeNode*> loopStack;
        TreeNode* curr = root;
        TreeNode* prenode = NULL;
/*
      3
   /    \
  5      2
 / \    / \
1   4  6   7

Sample Output

1 4 5 6 7 2 3
 */
        loopStack.push(root);
        while(!loopStack.empty()){
            curr = loopStack.top();

            // if it's just a leaf node, or its children have been visited, we will print it.
            if((curr->left == NULL && curr->right== NULL) ||
                /* after visit right leaf node, 
                and then we will visit root node, so we just need to check it's right pointer.*/
                curr->right == prenode/* || curr->left == prenode*/){
                //(prenode != NULL && (curr->right == prenode || curr->left == prenode))){
                result.push_back(curr->val);
                loopStack.pop();
                prenode = curr;
            }else{
                //后序遍历：左右根 , 入栈顺序，应该是 root right left
                if(curr->right!=NULL)  
                    loopStack.push(curr->right);  
                if(curr->left!=NULL)  
                    loopStack.push(curr->left); 
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

    vector<int> result = s.postorderTraversal_recursive(proot);
    for (int i = 0; i < result.size(); ++i)
    {
        cout<<result[i] << " ";
    }
    cout<<endl;

    vector<int> result2 = s.postorderTraversal(proot);
    for (int i = 0; i < result2.size(); ++i)
    {
        cout<<result2[i] << " ";
    }
    cout<<endl;

	return 0;
}