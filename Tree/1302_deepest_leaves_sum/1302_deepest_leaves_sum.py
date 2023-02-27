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

            