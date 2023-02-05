# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
중복된 값을 찾아야 하므로, dict count를 통해 frequency를 확인한 뒤, 
값이 2 이상이 있을 경우 true로 반환하기로 했다. 
반대로 생각하면, 1 만 있는 경우를 제외하면 모두 true이므로, set으로 만들 었을 때, 길이가 1이고 value가 1인 경우가 distict하다고 볼 수 있다. 

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
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Int array -> dict check 
        count = defaultdict(int)
        for i in nums:
            count[i] += 1
        print(count)
        

        duplicate_set = set(count.values())
        print(duplicate_set)
        # {1,2} = 2 exist = true 
        # {1} = 1 exist = false
        # {2,3} = 2 exist = true
        # {2} = 2 exist = true 

        return not(1 in duplicate_set and len(duplicate_set) == 1)
```