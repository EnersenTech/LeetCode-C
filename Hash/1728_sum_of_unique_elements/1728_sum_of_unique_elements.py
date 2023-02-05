from collections import defaultdict


class Solution:
    def sumOfUnique(self, nums: list[int]) -> int:
        # unique sum 
        # dict 
        unique_nums = defaultdict(int)
        ans = 0


        for num in nums:
            unique_nums[num] +=1

        for x,y in unique_nums.items():
            if y == 1:
                ans += x
        return ans

    

