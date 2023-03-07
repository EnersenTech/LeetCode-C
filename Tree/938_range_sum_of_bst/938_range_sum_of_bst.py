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
        
    