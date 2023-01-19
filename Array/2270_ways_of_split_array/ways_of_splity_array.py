class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        # sub array 
        # prefix sum 
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            prefix.append(nums[i] + prefix[-1])
        # prefix = [10, 14, 6, 13]
        ans = 0
        
        for j in range(len(prefix)-1):
            # cmp prefix with queries 
            # i.e.
            # 10 >= sum([1,3]) = prefix[3] - prefix[0]  = 3
            # 14 >= sum([2,3]) = prefix[3] - prefix[1] = -1 
            # ...
            curr = prefix[len(prefix)-1] - prefix[j] 
            if prefix[j] >= curr:
                ans += 1 
            
        return ans