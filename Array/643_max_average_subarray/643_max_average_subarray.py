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
                
