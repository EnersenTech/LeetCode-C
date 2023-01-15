# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Square를 한 다음에 sort를 하는 것은 NlogN의 complexity가 소비되므로, Two pointer를 이용하기로 했다. 
<br>
Left와 Rigth를 기준으로 비교하여 절댓값이 더 큰 Index를 새로운 array에 할당하고 
pointer를 업데이트 하는 방식이다.

# Approach
<!-- Describe your approach to solving the problem. -->


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
 $$O(1)$$

# Code
```
#include <vector>

class Solution {
    public:
        std::vector<int> sortedSquares(std::vector<int>& nums){
            int n = nums.size();
            int left = 0;
            int right = n - 1;

            std::vector<int> ans(n);

            for(int i = n -1; i >= 0; i--){
                int square;
                if(abs(nums[left]) > abs(nums[right])){
                    square = nums[left];
                    left++;
                }else{
                    square = nums[right];
                    right--;
                }
                ans[i] = square * square;
            }
            return ans;
        }
};
```