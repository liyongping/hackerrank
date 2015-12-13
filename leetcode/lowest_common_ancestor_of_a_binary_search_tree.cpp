#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 
在二叉查找树种，寻找两个节点的最低公共祖先

 Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
  “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL || root == NULL)
            return NULL;
        //if p,q < root, check left
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        //if p,q > root, check left
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        //if p < root < q, return root
        //if p or q == root, return root
        return root;
        
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
    cout<<s.maxDepth(proot)<<endl;

    /* code */
    return 0;
}