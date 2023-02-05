from collections import defaultdict

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
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