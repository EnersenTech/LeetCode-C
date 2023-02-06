# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음은 split을 이용해서 directory를 구분하고 ..의 경우 one level up하면 된다는 생각으로 시작했다.
그러나 empty string의 경우가 계속 stack에 들어가서 어떻게 처리할 지 고민하다가 시간이 지체되었다. 
continue를 통해 loop를 no-op로 진행하면 되는 것을 여러번의 시도 끝에 할 수 있었다. 


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
    def simplifyPath(self, path: str) -> str:
        # '/'
        # '/home/'
        # except first '/' replace all '//' to '/' and then last '/' removed
        # .. refer to one level up, if '/' root, then just return 
        # '/home/..' = '/'
        
        simplified_path = []
        
        for i in path.split('/'):
            if i == '..':
                if simplified_path:
                    simplified_path.pop()
            elif i == "." or not i:
                continue
            else:
                simplified_path.append(i)
                
        print(simplified_path)
                
        result = "/" + "/".join(simplified_path)
            
        
        return  result
        
        
        
```