# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Window Sliding의 개념을 응용하여 풀기로 했다. 
우선 0을 포함할 경우 Flip하고 최대 Flip 갯수가 k 이므로, flip을 base case로 삼았다. <br>
만약 flip 갯수가 k를 넘길 경우 left bound를 이동시킨다. <br>
언제까지? <br>
left bound가 0을 만날 때 까지. <br>
만약 left bound가 0을 만날 경우 초과된 Flip을 넘길 수 있기 때문이다. <br>

# Approach
<!-- Describe your approach to solving the problem. -->
i.e.

list = [1,1,1,0,1,0] 
k = 1

[1,1,1,1] r = 3, l = 0, window = r - l + 1 = 4
[1,1,1,1,1,0] overflow! 
[1,1,1,0,1,0] -> [x,x,x,x] [1,1] separate window
r = 5, l = 4, window = r - l + 1 = 2

Move left in order to meet the above process.

if l == 0:
    break conditional loop
Increment l 

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
    def longestOnes(self, nums: List[int], k: int) -> int:
        curr = 0 # num of zero binary flipped
        left = 0 # left bound
        ans = 0 # total length of window 
        
        for right in range(len(nums)):
            # if 0, then flip it and add to curr 
            if nums[right] == 0:
                curr += 1
            # Break Rule 
            while curr > k:
                # if 0, then flip it and decrement curr 
                if nums[left] == 0: 
                    curr -= 1
                # Left move 
                left += 1
                
            ans = max(ans ,right - left + 1)
        return ans      


```