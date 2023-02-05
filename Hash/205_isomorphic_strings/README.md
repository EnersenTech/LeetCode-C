# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
string s의 char를 key로 하고 string t의 char를 value로 하는 Hash-map을 제작하였다. 
i.e. 
egg : add
{e : a, g: d}
그 다음 Hash-map의 정보를 바탕으로 string s를 convert한 dummy_string과 t가 같다면, true 
아니면 false로 두기로 했다. 
단, 같은 char를 map할 수 없으므로 만약 이미 map이 되어있다면 생략한 뒤, 에러가 발생한다면 False 값을 주었다. 


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
    def isIsomorphic(self, s: str, t: str) -> bool:
        # dict 
        # e g g 
        # a d d 
        # e -> a 
        # g -> d

        # e : 'a'
        # g : 'b'

        s_string = dict()
        dummy_string = []

        
        for i in range(len(s)):
            # No duplicate 
            if t[i] not in s_string.values():
                s_string[s[i]] = t[i] 

        print(s_string)

        # convert back 
        for j in range(len(s)):
            if s[j] not in s_string:
                return False
            dummy_string.append(s_string[s[j]])

        print("".join(dummy_string))
        return "".join(dummy_string) == t
        
        
```