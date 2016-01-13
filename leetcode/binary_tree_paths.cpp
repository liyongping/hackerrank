#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

/*
 Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]

 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<string> paths;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      binaryTreePaths(root, "");
      return paths;
    }

    void binaryTreePaths(TreeNode* root, string prePath) {
        if(root == NULL)
          return;
        string currPath = "";
        string strVal = "";
        int2str(root->val, strVal);

        if(prePath.empty()){
            currPath = strVal;
        }else{
            currPath = prePath + "->" + strVal;
        }
        if(root->left == NULL && root->right == NULL){
            // it's a leaf node, exit
            paths.push_back(currPath);
        }else{
            binaryTreePaths(root->left, currPath);
            binaryTreePaths(root->right, currPath);
        }
    }
    void int2str(const int &int_temp,string &string_temp)  
    {  
            stringstream stream;  
            stream<<int_temp;  
            string_temp=stream.str();   //此处也可以用 stream>>string_temp  
    }
};


int main(int argc, char const *argv[])
{
  /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    
        7    2    

   */
	  TreeNode *proot = new TreeNode(5);
    proot->left = new TreeNode(4);
    proot->right = new TreeNode(8);

    proot->left->left = new TreeNode(11);
    proot->left->left->right = new TreeNode(2);
    proot->left->left->left = new TreeNode(7);

    proot->right->left = new TreeNode(13);
    proot->right->right = new TreeNode(4);

	  Solution s;
    vector<string> paths = s.binaryTreePaths(proot);
    for(unsigned i = 0; i < paths.size(); ++i) {
      cout<< paths[i] << endl;
    }

	return 0;
}