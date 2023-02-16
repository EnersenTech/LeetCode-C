# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
각각의 Max value와 비교가 필요하다. 

R(node.left, max_value)
R(node.right, max_value)

또한, good nodes의 갯수를 count해야 하므로 
return count 

if node.val >= max_value 

# Approach
<!-- Describe your approach to solving the problem. -->
상기 조건을 만족하기 위해 우선 dfs function을 만들었다. 
dfs(node, max_value)

base case는 node == None 
return 0 

count = left + right 


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
    def goodNodes(self, root: TreeNode) -> int:
        # Each node has to be compared 
        def dfs(node, max_val):
            if not node:
                return 0 
            
            left = dfs(node.left, max(max_val, node.val))
            right = dfs(node.right, max(max_val, node.val))

            ans = left + right

            if node.val >= max_val:
                ans += 1

            return ans

        
        return dfs(root, float("-inf"))
```