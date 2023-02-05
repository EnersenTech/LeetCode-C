# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
문제가 잠시 이해가 안 갔지만, 예시를 자세히 보니 0을 prefix로 하는 sum array를 altitude로 하는 문제였다. 
prefix sum의 방식으로 
prefix = 0 
나머지는 gain list를 iterate하면서 append하는 방식으로 altitude array를 업데이트 했다. 
마지막은 Max를 통해 가장 높은 값을 return.

# Approach
<!-- Describe your approach to solving the problem. -->
상기 동일

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
    def largestAltitude(self, gain: List[int]) -> int:
        # 0 0-5 0-5+1 0-5+1+5 ... 
        # Prefix = 0 
        # Prefix sum
        prefix = 0 
        altitude = [prefix]

        for right in range(len(gain)):
            altitude.append(gain[right]+altitude[-1])
        print(altitude)
        return max(altitude)

        


        
```