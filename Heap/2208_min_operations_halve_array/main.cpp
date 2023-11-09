#include <iostream>
#include <vector>
#include <queue> 
#include <numeric>


class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        // Convert vector to heap DS 
        std::priority_queue<double> pq = std::priority_queue<double> (nums.begin(), nums.end());

        // Total sum of nums
        double nums_sum = 0;
        nums_sum = std::accumulate(nums.begin(), nums.end(), nums_sum);

        // Half of nums 
        double half = nums_sum;

        // Operation counter 
        unsigned int opCounter = 0; 

        while(nums_sum / 2 < half){
            double max_val = pq.top(); 
            pq.pop();
            max_val = max_val / 2; 
            pq.push(max_val);

            half -= max_val;

            opCounter += 1;
        }
        return opCounter;
    }
};

int main(void){
    //std::vector<int> test_input = {5,19,8,1};
    std::vector<int> test_input = {3,8,20};

    Solution solution; 

    int ans = solution.halveArray(test_input);
    std::cout << ans << std::endl;

    return 0;
}