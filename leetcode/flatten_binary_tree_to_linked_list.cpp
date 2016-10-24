/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

 */


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
    // recursive
    void flatten1(TreeNode* root) {
        if(root == NULL)
            return;
        traversal(root, NULL);

    }

    // 把root变成链表后，tail跟在链表后
    TreeNode* traversal(TreeNode* root, TreeNode* tail){
        if(root == NULL)
              return tail;
        root->right = traversal(root->left, traversal(root->right, tail));
        root->left = NULL;

        return root;
    }

    // iterative
    void flatten(TreeNode* root){
        if(root == NULL)
            return;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            auto curr = s.top();
            s.pop();

            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);

            curr->left = NULL;
            if(!s.empty())
              curr->right = s.top();
        }
    }
};