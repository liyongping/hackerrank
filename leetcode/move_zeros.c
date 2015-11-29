#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize);

int main(int argc, char const *argv[])
{
    int i=0,j=0;

    int array[2] = {1,0};

    moveZeroes(array,2);

    for (i = 0; i < sizeof(array); ++i)
    {
        printf("%d\n", array[i]);
    }
    
}

void moveZeroes(int* nums, int numsSize) {
    int i = 0, nzp = 0;
    
    if(nums == NULL || numsSize == 1)
        return;
    
    
    
    for(i = 0; i< numsSize; i++){
        if(nums[i] != 0){
            continue;
        }
        
        //nums[i] == 0, nums[i+1] != 0
        if((i+1 < numsSize) && nums[i+1] != 0){
            nums[i] = nums[i+1];
            nums[i+1] = 0;
            
            if(i+2 == numsSize)
                break;
        }
        else{ //nums[i] == 0, nums[i+1] == 0
            // find non-zero position
            for(nzp = i+2; nzp < numsSize; nzp++){
                if(nums[nzp] != 0){
                    // found it, return
                    break;
                }
            }
            
            // found it
            if(nzp != numsSize){
                // swap the zero with non-zero
                nums[i] = nums[nzp];
                nums[nzp] = 0;
            }else{ // not found it, the rest after this i position is zero, exit
                break;
            }
        }
    }
}
