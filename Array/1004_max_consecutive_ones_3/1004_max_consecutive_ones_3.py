class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
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

