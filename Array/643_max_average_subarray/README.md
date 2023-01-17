# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Window Sliding 방법을 이용하여 문제를 풀기로 했다. 
sub-array 자체를 iterate할 경우 N^2만큼의 시간이 걸리지만, 
left, right bound를 이동하며 풀 경우 2N만큼의 시간이 걸린다.

nums = [1,12,-5,-6,50,3], k = 4

우선 curr를 incremenet하면서 k와 같을 경우를 생각했다. 
k 보다 작을 경우에는 값을 더한다. 

curr += nums[right] # 1 + 12 - 5 - 6
k와 같을 경우, average를 구한다. 
    ans = sum(curr) / right - left  

left를 increment

이 과정 중에 right가 +되면서, 최초 left == 0일 경우를 빼주어야 한다.

마지막으로 Max를 구하면 된다.
 
# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$, Amortized analysis 
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
 $$O(1)$$

# Code
```
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        left = curr = 0
        ans = float('-inf')
        
        for right in range(len(nums)):
            curr += nums[right]
            while(right - left + 1 >= k):
                if left != 0:
                    curr -= nums[left -1]
                ans = max(ans, curr / (right - left + 1))
                left += 1
            
        return ans
```