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
        
        
        