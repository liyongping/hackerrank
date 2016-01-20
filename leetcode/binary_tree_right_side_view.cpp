#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightValue;
        findRightNode(root, 0, rightValue);
        return rightValue;
    }

    void findRightNode(TreeNode* root, int level, vector<int> &rightValue){
        if(root == NULL)
            return;

        // every level just add a node.
        if(rightValue.size() == level){
            rightValue.push_back(root->val);
        }

        // we traversal right node firstly, so just rightest node will be saved.
        findRightNode(root->right, level+1, rightValue);
        findRightNode(root->left, level+1, rightValue);
    }

    //!!!
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> rightValue;
        queue<TreeNode*> levelQueue;

        if(root){
            levelQueue.push(root);
            levelQueue.push(NULL);
        }

        while(!levelQueue.empty()){
            TreeNode* curr = levelQueue.front();
            levelQueue.pop();


            rightValue.push_back(curr->val);



            if(curr->left)
                levelQueue.push(curr->left);
            if(curr->right)
                levelQueue.push(curr->right);
        }

        return rightValue;
    }
};

void printVector(vector<int> &list){
    for (int i = 0; i < list.size(); ++i)
    {
        cout << list[i] << " ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    /*
      3
   /    \
  5      2
 / \    / \
1   4  6   7
     */
    TreeNode *proot = new TreeNode(3);
    proot->left = new TreeNode(5);
    proot->right = new TreeNode(2);

    proot->left->left = new TreeNode(1);
    proot->left->right = new TreeNode(4);

    proot->right->left = new TreeNode(6);
    proot->right->right = new TreeNode(7);

    Solution s;
    vector<int> rightValue = s.rightSideView(proot);
    printVector(rightValue);

    vector<int> rightValue2 = s.rightSideView2(proot);
    printVector(rightValue2);

    return 0;
}