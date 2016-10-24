/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rs;
        traverse(root, 1, rs, true);
        return rs;
    }
    
    void traverse(TreeNode* root, int level, vector<vector<int>> &rs, bool left_to_right){
        if(root == NULL)
            return;

        // add a new node for new level
        if(rs.size() < level){
            rs.push_back(vector<int>());
        }

        
        if(left_to_right)
            rs[level-1].push_back(root->val);
        else
            rs[level-1].insert(rs[level-1].begin(), root->val);

        traverse(root->left, level+1, rs, !left_to_right);
        traverse(root->right, level+1, rs, !left_to_right);
    }
};