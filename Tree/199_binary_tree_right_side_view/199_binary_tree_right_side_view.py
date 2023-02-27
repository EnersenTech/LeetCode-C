# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        if not root:
            return []
        # DFS or BFS 
        # Init root
        queue = deque([root])

###        ans = []

        while queue:
            nodes_in_current_level = len(queue)

            ans.append(queue[-1].val)
            # print(queue[-1])
            # print(queue[-1].val)
            
            
            # print(queue)
            # print(queue)
            for _ in range(nodes_in_current_level):
                node = queue.popleft()


                if node.left:
                    queue.append(node.left)
                    
                if node.right:
                    queue.append(node.right)
                    
        return ans