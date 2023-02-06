# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
stack에 char를 append하고 만약에 stack[-1]인 prev가 char과 같다면 duplicates하니까 pop하는 형식으로 접근.

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
class Solution:
    def removeDuplicates(self, s: str) -> str:
        # abbaca 
        # bb pop 
        # aaca
        # aa pop
        # ca 
        stack = []

        for c in s:
            if stack and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)
        print(stack)
        return "".join(stack)
```