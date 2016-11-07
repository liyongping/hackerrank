/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int mid = (nums1.size()+nums2.size())/2;

        int i = 0;
        while(i<mid){
        	if(nums1[p1] < nums2[p2])
        		p1++;
        	else
        		p2++;
        	
        }
    }
};