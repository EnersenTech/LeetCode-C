# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Array split 조건에서 prefix sum을 비교하여 split 여부를 판단하므로 prefix sum logic을 사용했다. <br>
zero-index 부터 시작하여 나머지 sum을 비교하므로 우선 prefix sum array를 만든 후  <br>
비교하며 split이 가능한 지 확인했다. <br>
비교 과정에서는 query sum을 이용했다. <br>


# Approach
<!-- Describe your approach to solving the problem. -->
Make prefix sum array 
compare prefix with queries, where queries x,y is the sum from x to y.


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(2n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        # sub array 
        # prefix sum 
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            prefix.append(nums[i] + prefix[-1])
        # prefix = [10, 14, 6, 13]
        print(prefix)
        ans = 0
        
        for j in range(len(prefix)-1):
            # cmp prefix with queries 
            # i.e.
            # 10 >= sum([1,3]) = prefix[3] - prefix[0]  = 3
            # 14 >= sum([2,3]) = prefix[3] - prefix[1] = -1 
            # ...
            curr = prefix[len(prefix)-1] - prefix[j] 
            print(curr)
            if prefix[j] >= curr:
                ans += 1 
            
        return ans
            

```