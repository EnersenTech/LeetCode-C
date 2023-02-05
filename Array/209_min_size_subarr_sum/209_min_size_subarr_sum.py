class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        # subarray, sum, condition = Sliding Windows 
        left = curr = ans = 0 
        
        for right in range(len(nums)):
            curr += nums[right]

            while target <= curr:
                # ans = right - left + 1
                if ans == 0: 
                    ans = right - left + 1
                else:
                    ans = min(ans, right - left + 1)
                curr -= nums[left]
                # Move left and check sub-array length 
                left += 1

                # ans = right - left + 1 
                # ans = min(ans, right - left + 1)
                print(ans)

            
        return ans

        