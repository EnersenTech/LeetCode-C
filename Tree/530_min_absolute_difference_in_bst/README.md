# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
BST의 특성을 이용하여 elements를 ascending order로 하는 list를 만들었다. 
DFS help function을 사용하였고 list의 loop를 돌면서 min difference를 구하면 될 것 같았다. 

# Approach
<!-- Describe your approach to solving the problem. -->
return a value of dfs function.
Insert root node to the dfs help function. 
With infinity values compare each elements of the given list to get a difference. 

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
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        # Min absolute diff 
        # Rightmost leaf & Leftmost leaf 
        def dfs(node):
            if not node:
                return []
            left = dfs(node.left)
            right = dfs(node.right)
            return left + [node.val] + right
        
        values = dfs(root)
        ans = float("inf")

        for i in range(1, len(values)):
            ans = min(ans, values[i]- values[i - 1])

            
            

        return ans
```