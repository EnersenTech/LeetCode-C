class Solution:
    def makeGood(self, s: str) -> str:
        # i, i+1 
        
        stack = []
        for c in s:
            # P p
            if stack and c.islower() and c.upper() == stack[-1]:
                stack.pop()
            # p P
            elif stack and c.isupper() and (c.lower() == stack[-1]):
                stack.pop()
            else:
                stack.append(c)
            
            
        print(stack)
        return "".join(stack)