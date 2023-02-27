# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음 생각은 level 별로 queue를 업데이트 할 때, left, right의 순서를 바꿔주면 될 것이라고 생각했다. 
level 별로 분기를 주기 위해 self.current var를 주어서 modulo를 사용했다. 
그러나, left, right가 없을 경우 testcase에서 오류가 발생해, 각 레벨 별로 sub array에 할당하여 
reverse를 한 뒤, answer array에 push 하는 형식으로 해결했다.

# Approach
<!-- Describe your approach to solving the problem. -->
상기 동일

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
```