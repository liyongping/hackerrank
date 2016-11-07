/*
 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
 */


class Solution {
public:
	int firstMissingPositive1(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int i = 0;
		int n = nums.size();
		// skip negative element
		while (i < n && nums[i] <= 0)
			i++;

		// the first positive element is 1
		int f = 1;
		while (i < n) {
			// skip next same element
			while (i < n - 1 && nums[i] == nums[i + 1])
				i++;

			if (nums[i] != f)
				break;
			f++;
			i++;
		}

		return f;
	}

	int firstMissingPositive(vector<int>& nums) {
		int i=0, n = nums.size();

		while(i < n) {

		    if(nums[i] > 0 && nums[i] != i+1
		        // if they are same, wouldn't swap
		        && nums[i]-1 < n && nums[i] != nums[nums[i]-1])
		    {
		    	swap(nums[i],nums[nums[i]-1]);
		    }
		    else
		    	i++;
		}

		for(int j=0; j < n; j++){
			if(j+1 != nums[j])
				return j+1;
		}

		return n+1;
	}
};