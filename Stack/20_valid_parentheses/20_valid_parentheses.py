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
            
            