# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Subarray, sum, condition등을 고려했을 때, Sliding Windows 접근법을 사용했다. <br>
subarray의 합을 curr 변수에 담아 target 보다 크거나 같을 경우 subarray length를 업데이트 한 뒤, 
subarray를 조정했다.
다만, minimal length를 찾아내는 과정에서 ans init이 0이므로 min method 사용 시 0으로 귀납되는 것을 막고자
최초 ans == 0일 경우 right - left + 1로 업데이트를 진행하였다. 

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
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        # subarray, sum, condition = Sliding Windows 
        left = curr = ans = 0 
        
        for right in range(len(nums)):
            curr += nums[right]

            while target <= curr:
                # ans = right - left + 1
                if ans == 0: 
                    ans = right - left + 1
                else:
                    ans = min(ans, right - left + 1)
                curr -= nums[left]
                # Move left and check sub-array length 
                left += 1

                # ans = right - left + 1 
                # ans = min(ans, right - left + 1)
                print(ans)

            
        return ans

        
```