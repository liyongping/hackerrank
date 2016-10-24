/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode *>> map;
        traversal(root, 1, map);
    }
    
    void traversal(TreeLinkNode *root, int level, vector<vector<TreeLinkNode *>> & map){
        if(root == NULL)
            return;
        if(map.size() < level)
            map.push_back(vector<TreeLinkNode *>());
        
        int n = map[level-1].size();

        if(n == 0) // for the first element(the rightest node), don't need to set next pointer
            map[level-1].push_back(root);
        else{
            root->next = map[level-1][n-1];
            map[level-1].push_back(root);
        }
        
        // traversal from right to left
        traversal(root->right, level+1, map);
        traversal(root->left, level+1, map);
    }

    // loop 
    void connect2(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode * next = nullptr; // the first node of next level
            TreeLinkNode * prev = nullptr; // previous node on the same level
            for (; root; root = root->next) {
                if (!next) next = root->left ? root->left : root->right;
                if (root->left) {
                    if (prev) 
                        prev->next = root->left;
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};  