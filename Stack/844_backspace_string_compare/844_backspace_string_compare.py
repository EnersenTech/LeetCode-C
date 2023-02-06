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