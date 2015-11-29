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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both of them are null, they are identical
        if(p == NULL && q == NULL)
            return true;
        
        // one is null, one isn't null, they are different
        if(p == NULL && q != NULL)
            return false;
        
        if(p != NULL && q == NULL)
            return false;
        
        // values are different, they are different
        if(p->val != q->val)
            return false;
        
        // Use recursion to go through their children to check if they are identical.
        bool leftR = isSameTree(p->left, q->left);
        if(!leftR)
            return false;
        bool rightR = isSameTree(p->right, q->right);
        if(!rightR)
            return false;
        
        return true;
    }
};