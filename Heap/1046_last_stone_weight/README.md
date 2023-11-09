# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
가장 높은 숫자를 뽑는 과정을 반복.
min/max element access의 효율이 가장 높은 DS는 Heap이다. (O(1))
다른 제약사항이 없기 때문에 Array vector를 Heap으로 변경하여 진행.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Array vector -> Heap 변경
2. Heap의 size가 1개 남을 때 까지 반복하므로, break point 지정 (if heap.size() == 1 break)
3. 최대 반복 횟수는 Heap의 사이즈 만큼 
4. x == y 경우 x,y 전부 delete (if x == y pop)
5. x > y 경우, -y + x 값을 add (if x > y push(-y + x))


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(logn)$$ Heap 사이즈 만큼 반복 

# Code
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (!pq.empty()) {
            if (pq.size() == 1) return pq.top();
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x) pq.push(y - x);
        }
        return 0;
    }
};
```