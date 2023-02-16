# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
단순하게 left, right의 depth min을 구하려고 했으나
test case에서 left only, right only tree가 존재하여 경우의 수를 나눴다. 
root.right == null 
-> left only dfs + 1
root.left == null
-> right only dfs + 1
else
-> min(left, right) + 1

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
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        if root.left == None: 
            return self.minDepth(root.right) + 1
        if root.right == None:
            return self.minDepth(root.left) + 1
        else:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        
    
            
        #[2,null,3,null,4,null,5,null,6]
        #[3,9,20,null,null,15,7]
```