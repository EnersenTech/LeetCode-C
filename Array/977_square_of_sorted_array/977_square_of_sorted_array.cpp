#include <vector>

class Solution {
    public:
        std::vector<int> sortedSquares(std::vector<int>& nums){
            int n = nums.size();
            int left = 0;
            int right = n - 1;

            std::vector<int> ans(n);

            for(int i = n -1; i >= 0; i--){
                int square;
                if(abs(nums[left]) > abs(nums[right])){
                    square = nums[left];
                    left++;
                }else{
                    square = nums[right];
                    right--;
                }
                ans[i] = square * square;
            }
            return ans;
        }
};