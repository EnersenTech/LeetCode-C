# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Find node from root 
        # L = p R = q 
        # L 과 R이 같은 subtree에 있다면, depth가 높은 것이 LCA == 먼저 발견된 Node 
        # L 과 R이 다른 subtree에 있다면, root가 LCA 

        # Check if L and R nodes in subtree

        if not root:
            return None

        if root == p or root == q:
            return root 

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root 

        if left:
            return left 
        
        if right:
            return right

        
            

        