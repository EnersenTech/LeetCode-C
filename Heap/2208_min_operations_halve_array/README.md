# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
nums = [5,19,8,1]

sum(nums) = 33 

original 1 + 5 + 8 + 19  = 33 
Trial 1 -> 19/2 = 9.5 ... 33 - 9.5 = 23.5 > 16.5 
Proceed 
Trial 2 -> 9.5/2 = 4.75 ... 18.5 > 16.5 
Proceed 
Trial 3 -> 8/2 = 4 ... 14.5 < 16.5 
Done! 

합계에서 가장 적은 횟수로 절반을 만들기 위해서는 큰 수를 절반으로 만드는 것이다. 가장 큰 수를 찾고 그 수를 절반으로 만들어서 넣고 합계를 구하고 
해당 합계가 기존의 절반 보다 작아야 한다.
반복적 작업 및 가장 큰 수를 계속 찾아야 하므로 Max Heap이 바람직하다.

# Approach
<!-- Describe your approach to solving the problem. -->
처음 아이디어는 vector sum을 구하고 Heap을 업데이트 하며 Heap sum을 사이클 마다 체크하려고 했다. Heap의 sum이 vector sum보다 작으면 break하는 형식으로. 

그러나, Heap의 sum을 구하는 방법을 몰라 별도의 while loop를 만들어서 실행했더니 Test Input 갯수가 많아지면, 너무 실행이 오래 걸려서 실패했다. 2중 루프를 도는 것이므로 $$O(N^2)$$이 되어 버렸다.

그래서 그냥 기존 sum에서 max를 half한 값을 빼서 그 값이 vector sum보다 작으면 break하도록 했다. 
이렇게 하면 굳이 Heap의 elements sum을 구하지 않아도 된다.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(nlogn)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$


# Code
First trial (passed 25/62) Time Limit Exceeded
```
class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        // Convert vector to heap DS 
        std::priority_queue<double> pq = std::priority_queue<double> (nums.begin(), nums.end());

        // Total sum of nums
        double nums_sum = 0;
        nums_sum = std::accumulate(nums.begin(), nums.end(), nums_sum);

        
        // Operation counter 
        unsigned int opCounter = 0; 

        // 
        while(nums_sum / 2 < this->AddHeap(pq)){
            //if(nums_sum / 2 > this->AddHeap(pq)) return opCounter;
            double max_val = pq.top(); 
            pq.pop();
            max_val = max_val / 2; 
            pq.push(max_val);

            opCounter += 1;
        }
        return opCounter;
    }

    double AddHeap(std::priority_queue<double> pq){
        std::priority_queue<double> pq_tmp = pq;
        double pq_sum = 0;
        while(!pq_tmp.empty()){
            pq_sum += pq_tmp.top();
            pq_tmp.pop();
        }
        return pq_sum;
    }
};


```
Second Trial (Passed!)
```
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

        // 33 16.5  33 - 9.5 =  
        while(nums_sum / 2 < half){
            //if(nums_sum / 2 > this->AddHeap(pq)) return opCounter;
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
```
