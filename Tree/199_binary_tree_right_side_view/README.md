# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음에는 문제를 잘못 이해하여, left subtree append를 하지 않고 right subtree의 value만 읽는 줄 알았다. 
그러나 testcase에서 예외를 보고 나서 각 level의 queue의 rightmost value를 읽으면 되겠다고 생각하고 문제를 풀었다. 

# Approach
<!-- Describe your approach to solving the problem. -->
i.e. [1,2,3,null,5,null,4]

level 0 = [1]
level 1 = [2,3]
level 2 = [5,4]

answer.append(queue[-1].val)



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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        if not root:
            return []
        # DFS or BFS 
        # Init root
        queue = deque([root])

        ans = []

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

```