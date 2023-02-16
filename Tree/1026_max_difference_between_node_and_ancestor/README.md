# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
max value와 min value를 구해야 max difference가 나오므로 
각 node의 max value, min value를 update하는 방향으로 가면 좋을 것 같다. 
모든 path가 같은 subtree에서 발생하므로 단순히 max value - min value만 해도 된다.
leaves를 만나면 그 동안 업데이트한 max value, min value differnce를 return 하면 해당 path의 max difference가 나온다.


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
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(node, max_curr, min_curr):
            if not node:
                return max_curr - min_curr
            
            max_curr = max(max_curr, node.val)
            min_curr = min(min_curr, node.val)
                        
            
            left = dfs(node.left, max_curr, min_curr )
            right = dfs(node.right, max_curr, min_curr)
                        
            
            return max(left, right)
            
            
        return dfs(root, root.val, root.val)
```