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