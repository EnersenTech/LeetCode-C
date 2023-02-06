# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음 아이디어는 string을 iterate하면서 open일 경우 append하고 close일 때 pop을 하려고 했다. 
그러나 바로 종류를 맵핑해야 한다는 것을 깨닫고 Hash-map을 생성하여 open일 경우에는 push 하고 
close일 경우 pop한 prev값과 비교하여 일치할 경우에만 다음 과정을 넘어갔다. 
check를 해보니, close만 있을 경우가 존재하여 바로 else로 넘어가니 stack이 비어있을 때 False를 return했다.

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$, stack's size can grow linearly with the input size

# Code
```
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        # key value pair 
        # () {} []
        # if open push stack 
        # if closed pop stack 
        parentheses_pair = {'(':')', '[':']', '{':'}'}



        # ([{}])
        for char in s:
            if char in parentheses_pair:
                stack.append(char)
            else:
                if not stack:
                    return False
                prev = stack.pop()
                if parentheses_pair[prev] != char:
                    return False
            

        return not stack
            
            
```