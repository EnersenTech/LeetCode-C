# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        # Not root exception
        if not root:
            return []
        # Queue init
        queue = deque([root])

        ans = []
        while queue:
        # Each level check 
            nodes_current_level = len(queue)

            # queue = {treenode, treenode, treenode}
        
            max_val = float("-inf")

            for _ in range(nodes_current_level):
                node = queue.popleft()

                max_val  =  max(node.val,max_val)

                if node.right:
                    queue.append(node.right)
                if node.left:
                    queue.append(node.left)
            ans.append(max_val)
            print(max_val)

        return ans





    