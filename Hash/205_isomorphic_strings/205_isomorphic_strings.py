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
        
        