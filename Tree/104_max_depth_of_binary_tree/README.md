# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Recursion을 사용하여 문제를 해결하기로 했다. 
Binary Tree이므로 left or rigth 중 가장 긴 depth를 구하면 되니까 
left_node, right_node의 max를 구하면 된다. 
Leetcode에서는 root depth를 1로 취급하므로 마지막 return 값에 +1을 한다. 

# Approach
<!-- Describe your approach to solving the problem. -->
i.e. 
        3
      /   \
    9      20
          /   \
        15      7

root에서 left_depth를 하면 9가 current node가 된다. 
9의 입장에서 left_depth를 하면 0이 되고 
right_depth를 하면 0이 되므로 maxDepth의 값은 1이 된다. 
9 = 1

root에서 right_dpeth를 하면 20이 current node가 된다. 
20의 입장에서 left_depth를 하면 15가 되고 
15의 입장에서 보면 maxDepth의 값은 1이 된다. 
15 = 1
20의 입장에서 right_depth를 하면 7이 되고 
7의 입장에서 보면 maxDepth의 값은 1이 된다.
20의 입장에서 보면 maxDepth는 1 + 1이므로 2이다. 

root의 입장에서 left_depth는 1, right_depth는 2이므로 
2 + 1을 하면 maxDepth는 3이 된다. 


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
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        
        return max(left_depth, right_depth) + 1

```