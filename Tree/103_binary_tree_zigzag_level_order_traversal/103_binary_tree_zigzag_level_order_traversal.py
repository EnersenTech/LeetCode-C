# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # Left to Right 
        if not root:
            return []

        ans = []
        queue = deque([root])
        self.current_level = 0

        while queue:
            
            nodes_in_current_level = len(queue)

            # append queue 
            sub_array = []
            
            for _ in range(nodes_in_current_level):
                node = queue.popleft()

                sub_array.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            if self.current_level % 2 == 0:
                ans.append(sub_array)
            else:
                ans.append(reversed(sub_array))
            self.current_level += 1

        return ans