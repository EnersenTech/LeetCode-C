# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
각 트리 레벨당 최댓값을 저장하여 레벨이 변하는 구간에서 answer array에 append를 하는 형식으로 문제를 해결.

# Approach
<!-- Describe your approach to solving the problem. -->
for loop에서 각 tree node value에 접근 가능.  for loop 밖의 variable을 선언하고 loop에서 update한 뒤, 
max 값을 append

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





    
```