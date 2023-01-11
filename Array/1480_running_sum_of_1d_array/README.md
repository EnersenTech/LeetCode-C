# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
parameter int* returnSize를 제외하고 생각하면, loop를 돌면서 더하면 된다고 생각했다. 
아무리 찾아도 returnSize의 단서를 찾을 수 없어, Discussion을 참조하였다. 
returnSize는 array의 size 할당이라고 보면 된다. 
i.e. 
```    
nums = [1,2,3,4]

numsSize = 4

returned nums = [int, int, int, int]
```

# Approach
<!-- Describe your approach to solving the problem. -->
Local variable을 iterate하면서 index element만큼 더한다. 
더한 값을 element로 해서 array에 push

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
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
```