# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
p와 q가 어느 subtree에 있는지에 따라 다를 것 으로 생각했다. 
root가 존재한다면 웬만해서는 root가 LCA가 될 것이다. 
그러나 만약 p와 q가 한 쪽의 subtree에 있다면 그 left & right가 subtree가 될 것이다. 


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

        
            

        
```