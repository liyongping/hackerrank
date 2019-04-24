#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Sample Input

     3
   /   \
  5     2
 / \    / \
1   4  6   7

Sample Output

1 5 4 3 6 2 7

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        serialize(root, output) ;
        return output;
    }
    void serialize(TreeNode* root, string &output) {
        if(!root){
            output += "#";
            return;
        }
        output += to_string(root->val);
        serialize(root->left, output) ;
        serialize(root->right, output) ;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        int curr = 0;
        deserialize(&root, data, curr) ;
        return root;
    }
    
    void deserialize(TreeNode** root, string data, int& curr) {
        if(curr >= data.size())
            return;
        
        char currc = data[curr] ;
        curr++;
        // it's a valid node
        if(currc != '#'){
            TreeNode* node = new TreeNode(currc-'0');
            * root = node;
            
            deserialize(&node->left, data, curr);
            deserialize(&node->right, data, curr);
        }
        
    }
};


int main(int argc, char const *argv[])
{
	TreeNode *proot = new TreeNode(-1);
    proot->left = new TreeNode(0);
    proot->right = new TreeNode(1);
/*
    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    proot->right->left = new TreeNode(6);
    proot->right->right = new TreeNode(7);
*/
	Codec s;
    string xx = s.serialize(proot);
    cout << xx << endl;

    cout << s.deserialize(xx) << endl;

	return 0;
}