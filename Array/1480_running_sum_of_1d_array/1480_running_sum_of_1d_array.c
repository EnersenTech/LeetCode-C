/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
     int count = 0;
     *returnSize = numsSize; //size for the new array to be returned
    for(int i = 0; i < numsSize; i++){  
        count = count + nums[i]; // 0 + 1, 1 + 2, 
        nums[i] = count;
    }
    return nums;
}