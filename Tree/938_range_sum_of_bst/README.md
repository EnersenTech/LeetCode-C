# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
모든 nodes를 check하면서 [low, high] range에 있는 지 check하고 pass하면 
sum variable에 add하는 형식으로 접근했다. 

# Approach
<!-- Describe your approach to solving the problem. -->
Binary Tree에서 모든 values를 찾는 것이 좀 비효율적으로 생각된다. 
아직 Binary Search Tree를 보지 않았기 때문에 잘 모르겠지만, 그 쪽이 모든 node를 갈 필요각 없기에 
다른 방법으로 접근할 수 있을 것으로 판단된다. 

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
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        # BSF incursive 
        # iterate each level 
        # check all values and condition 
        # Add if condition passes 
        
        if not root:
            return 0

        queue = deque([root])

        ans = 0 
        while queue:
            
            nodes_in_current_level = len(queue)

            for _ in range(nodes_in_current_level):
                node = queue.popleft()
                if node.val in range(low, high + 1):
                    ans += node.val
                if node.right:
                    queue.append(node.right)
                if node.left:
                    queue.append(node.left)
        return ans           
        
    
```