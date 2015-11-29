/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        // invert the left node vs right node for current node.
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        // deal with its children
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};