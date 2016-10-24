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
};