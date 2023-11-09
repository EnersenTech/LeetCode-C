#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Convert vector to heap DS 
        std::priority_queue<int> pq = std::priority_queue<int>(stones.begin(), stones.end());

        // Repeat game until heap is empty
        while(!pq.empty()){
            // The very last one left, return val
            if(pq.size() == 1) return pq.top();
            int x,y; 
            x = pq.top(); 
            pq.pop();
            y = pq.top();
            pq.pop();
            if (x > y) pq.push(-y + x);
        }
        return 0;
    }
};

int main(void){
    std::vector<int> test_input = { 2,7,4,1,8,1 };

    Solution solution;
    int ans = solution.lastStoneWeight(test_input);

    std::cout << "Output : " << ans << std::endl;
    return 0;

}