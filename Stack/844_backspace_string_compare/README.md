# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
각각의 string을 iterate해서 '#' char 발견 시 pop하고 아닐 경우에는 append하는 직관적인 방법으로 해결했다. 
다만, pop을 하기 위해서는 stack이 empty하지 않아야 하며, '#'이 연속으로 나올 경우에는 append하지 말아야 하므로 몇 개의 조건을 추가했다. 

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
    def backspaceCompare(self, s: str, t: str) -> bool:
        # # denoted pop 
        s_stack = []
        t_stack = []

        for c in s:
            if c == '#' and s_stack:
                s_stack.pop()
            else:
                if c != "#":
                    s_stack.append(c)

        for c in t:
            if c == "#" and t_stack:
                t_stack.pop()
            else:
                if c != "#":
                    t_stack.append(c)
        
        print(s_stack)
        print(t_stack)

        return s_stack == t_stack
```