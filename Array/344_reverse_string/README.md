# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음에 in-place modification을 보지 못 하고 Dynamic Array로 할당해야 겠다는 생각을 했다. 
sSize +1 만큼의 char memory를 만들고 기존 s 값을 copy해서 넣은 다음 modification하려고 했다. 

그런데 Heap error가 나서 살펴보니, strcpy가 아니라 memcpy를 해야했다. 
NULL 여부인데, 다른 IDE에서는 작동하는데 Leetcode 검사에서는 허용하지 않았다. 

어쨌든 Two pointers로 First Index, Last Index 값을 Swap을 해주었다. 
그리고 나서 s parameter를 return하려고 보니 void type이었다. 

그래서 그냥 Dynamic array만들지 않고 동일한 로직을 구현했다. 

# Approach
<!-- Describe your approach to solving the problem. -->
하단 코드 comment 참조

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n/2)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```

// Error from strcpy()
// void reverseString(char* s, int sSize){
//     printf("%d ", sSize );
//     // char* tmp = (char *)malloc(sSize * sizeof(char));
//     // strcpy(s, tmp);
    
//     int left = 0;
//     int right = sSize-1;
//     while(left < right){
//         char tmp = s[left]; // h
//         s[left] = s[right];
//         s[right] = tmp;
//         left++;
//         right--;
//     }
// }


// void reverseString(char* s, int sSize){
//     char * tmp = (char *)malloc(sSize + 1 * sizeof(char));
//     memcpy(tmp, s, sSize);
//     int left = 0;
//     int right = sSize - 1;
    
//     while(left < right){
//         tmp[left] = s[right];
//         tmp[right] = s[left];
//         left++;
//         right--;
//     }
//     s = tmp;
// }

// 단순하게 생각하자. 
// Array를 Dynamic Array로 꼭 바꿀 이유는 없다. 
// 그러니까 dynamic allocation을 할 필요가 없다는 뜻이다. 
// 문제에서도 in-place modification을 하라고 했고 
// funcion type도 void이다. 
// 만약 위에처럼 dynamic하게 하려면, return char * 이렇게 해야한다. 


// 내가 dynamic array만든 것으로는 main에서 string parameter 자체를 바꾸는 것이 아니기 때문이다. 

void reverseString(char * s, int sSize){
    int left = 0;
    int right = sSize -1;
    while(left < right){
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
```