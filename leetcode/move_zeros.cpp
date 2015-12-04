#include <iostream>
#include <vector>
using namespace std;


/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

 */
void moveZeroes(vector<int>& nums);

int main(int argc, char const *argv[])
{
    int i=0,j=0;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);

    moveZeroes(nums);
    
    cout<<nums[0]<<endl;
    cout<<nums[1]<<endl;
    
}


    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        
        for(int i=0,j=0; i< nums.size(); i++){
            /* solution 1:
            
             if(nums[i] != 0 ){
                //nums[i] = nums[i]^nums[j];
                //nums[j] = nums[i]^nums[j];
                //nums[i] = nums[i]^nums[j];
                swap(nums[i], nums[j++]);
                //j++;
            }*/

            // s2
            if(nums[i] != 0 ){
                if(i!=j){ // swap it
                    nums[i] = nums[i]^nums[j];
                    nums[j] = nums[i]^nums[j];
                    nums[i] = nums[i]^nums[j];
                }
                //swap(nums[i], nums[j++]);
                j++;
            }
        }
    }
