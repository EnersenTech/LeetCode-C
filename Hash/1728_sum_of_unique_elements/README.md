# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음에 unique array를 만들기 위해 set을 이용하려고 했으나, 중복되는 elements를 제거하는 과정이 순탄치 않아
Hash-map으로 counting하기로 했다. 
counting이 1인 key의 sum을 구하면 된다. 

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$

# Code
```
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        # unique sum 
        # dict 
        

        unique_nums = defaultdict(int)
        ans = 0


        for num in nums:
            unique_nums[num] +=1
        
        print(unique_nums.items())
        for x,y in unique_nums.items():
            if y == 1:
                ans += x
        return ans

    


```