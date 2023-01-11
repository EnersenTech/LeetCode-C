# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
palindrome number를 string number로 바꾸는 것을 생각해봤었다. 
그러나, Math topic에 맞게 수학적으로 계산할 수 있는 방법이 있을 지 떠올리다가
Modulo를 생각했다. 121을 기준으로 하여 각각의 자릿수를 얻을 수 있으면 해결할 수 있을 듯 했다.
로직을 떠올리기 위해 다음과 같이 실험해 보았다.
i.e.
121 % 10 = 1
121 - 1 = 120
120 % 10 = 2
120 - 20 = 100
// Fail

121 % 10 = 1
121 - 1 = 120
120 % 10 = 2
120 - 2 = 118
// Fail

...

121 = 1 + 20 + 100
121 % 10 = 1
121 / 10 = 12.1 = 12
12 % 10 = 2
12 / 10 = 1.2 = 1
1 % 10 = 1
1 / 10 = 0.1 = 0
// Success

다음은 각각 얻은 modulo들을 iterator하는 중에 10 씩 곱하여 더하면 처음 x 값이 나오는 것을 깨닫고 실행했다.

# Approach
<!-- Describe your approach to solving the problem. -->
Intuition과 동일

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(logn)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```
bool isPalindrome(int x){
    // 121 
    // 1 + 20 + 100 = 121 

    // 121 % 10 = 1
    // x / 10 = 12.1
    // 12 % 10 = 2 
    // x / 10 = 1.2
    // 1 % 10 = 1
    if(x < 0) return false;
    int temp = x;
    unsigned long significant = 0;
    int modulo;
    while(temp){
       modulo = temp % 10; 
       significant = 10 * significant + modulo;
       temp /= 10;
    }
    if(x == significant) return true;
    return  false;
}
```