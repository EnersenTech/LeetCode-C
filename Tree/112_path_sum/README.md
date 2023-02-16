# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Iterative 방법 보다는 Rescursion이 훨씬 흔하게 쓰인다고 한다. 
Base case를 확인하자.
그래서 우선 leaf에 도달했을 때, path 동안의 sum을 축적해야 한다고 생각했다. 
leaf의 도달은 node.left & node.right가 null이면 그렇다. 
그리고 그 상황에서 targetSum과 같다면 True이다. 
만약 root가 없다면 그것은 False이다. 

그럼 loop condition을 살펴보자. 
path sum을 각각의 path에 넘겨야 한다면, 
R(node.left, path_sum)
R(node.right, path_sum)
이렇게 넘겨야 할 것이다. 

그렇다면 path_sum = node.val일 것이다. 
이렇게 넘겨서 R(node_left, path_sum) 혹은 R(node_right, path_sum) 중에 하나만 조건을 충족하는 것이 있다면
True일 것이다. 
그래서 return R(node_left, path_sum) or R(node_right,path_sum)

# Approach
<!-- Describe your approach to solving the problem. -->
path_sum을 넘기는 과정에서 각각의 stack function이 고유한 path_sum을 가지고 있어야 했다. 
따라서 helper function을 생성했다. 

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(node, curr):
            if not node:
                return False
            if node.left == None and node.right == None:
                return (curr + node.val) == targetSum

            curr += node.val
            left = dfs(node.left, curr)
            right = dfs(node.right, curr)

            # Either left or right path has target value, then True 
            return left or right 

        return dfs(root, 0)

        
```