/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end) {
		if (begin > end)
			return NULL;
        //int mid = start+(end-start)/2;
		int mid = (begin + end)/ 2 ;
		TreeNode* curr = new TreeNode(nums[mid]);

		curr->left = sortedArrayToBST(nums, begin, mid-1);
		curr->right = sortedArrayToBST(nums, mid + 1, end);

		return curr;
	}
};