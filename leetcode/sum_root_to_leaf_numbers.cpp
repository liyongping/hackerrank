#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.  
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
    int sum;
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dsfNumber(root,0);
        return sum;
    }

    void dsfNumber(TreeNode* root, int number){
        if(root == NULL)
            return ;
        int currValue = number*10 + root->val;

        if(root->left)
            dsfNumber(root->left, currValue);
        if(root->right)
            dsfNumber(root->right, currValue);

        if(root->left == NULL && root->right== NULL){
            sum += currValue;
        }
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
    cout<< s.sumNumbers(proot) << endl;

    return 0;
}