#include <stdlib.h>

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