# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
BFS를 통해 마지막 level의 values sum을 return하면 되겠다고 생각. 
while loop 마지막이 deepest leaves기 때문에 for loop에서 sum을 해서 return

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$
# Code
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        # Find leaves 
        if not root:
            return 0
        
        queue = deque([root])

        while queue:
            current_level = len(queue)

            

            sum_of_values = 0

            print(sum_of_values)

            for _ in range(current_level):
                node = queue.popleft()

                sum_of_values += node.val

                if node.right:
                    queue.append(node.right)

                if node.left:
                    queue.append(node.left)
        return sum_of_values

            

```