# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
주제인 Stack을 사용하는 것 자체에서 힌트를 얻었다.
open parentheses를 기점으로 close parentheses가 존재하면 pop을 시킨다.
Stack에는 open parentheses만 결과적으로 쌓일 것인데, stack size가 max depth가 된다. 
i.e. 
char *s = "(1 + 2 * (3 / 4))"
stack = '(' '('
stack.size = 2 
 

# Approach
<!-- Describe your approach to solving the problem. -->
Create a dummy stack with the size of original string array.
Compare character and push element into the stack.
return size of stack.
free stack

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

# Code
```
int maxDepth(char * s){
    // Given string cahr * s 
    // s is VPS 

    int string_length = strlen(s);
    int top = -1;
    int size;
    char * stack = NULL;
    stack = (char *)calloc(string_length, sizeof(char));


    for(int i=0; i< string_length; i++){
        if(s[i] == '('){
            top++;
            stack[top] = s[i];
        }else if(s[i] == ')'){
            top--;
        }
    }    
    
    size = strlen(stack);
    free(stack);

    return size;

}
```