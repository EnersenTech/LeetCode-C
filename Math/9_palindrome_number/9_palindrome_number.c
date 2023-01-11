typedef enum bool {
    true = 1,
    false = 0
} bool;

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