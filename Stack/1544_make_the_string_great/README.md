# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
i, i+1을 비교하여 소문자 대문자 pair가 같다면 pop을 하고 나머지는 append를 하기로 했다. 
그런데 처음 test case에서는 pP, Pp, PP와 같은 예시가 없기에 
and를 1줄에 전부 사용하려고 했다. 
i.e.
if stack and c.islower() and c.upper() == stack[-1] or c.isupper()...
뭔가 이상함을 감지했다. 
코드가 중복되거나 쓸데없이 길어지기 때문이었다. 

그래서 일단 정답을 제출하고 코드를 clean하게 바꾼 결과 
ASCII code를 이용하면 되었다. 
Absolute값으로 소문자 - 대문자 or 대문자 - 소문자가 32가 되면 같기 때문이다. 

if stack and abs(ord(c) - ord(stack[-1])) == 32:
위와 같이 바꿀 수 있다. 

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
```