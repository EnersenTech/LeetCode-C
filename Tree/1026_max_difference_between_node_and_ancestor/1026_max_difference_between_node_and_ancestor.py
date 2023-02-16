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