# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
F(n) = (s0 * 2^0) + (s1 * 2^1) + ... + (sn-1 * 2^n-1)
Find a length of list through iteration.
Calculate value with two power of n.
# Approach
<!-- Describe your approach to solving the problem. -->
Use pointer to iterate the list.
While head does not equal to the NULL, calculate value and add to the result.


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(2N)$$, As we are traversing the list in twice.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 #include<stdlib.h>
 #include<math.h>
int getDecimalValue(struct ListNode* head){
    int decimal_value = 0;
    int node_len = 0;
    struct ListNode* ptr = head; 
    while(ptr != NULL){
        node_len++;
        ptr = ptr -> next;
    }
    while(head  != NULL){
        node_len--;
        decimal_value += head -> val * pow(2, node_len);
        head = head -> next;
    }
    return decimal_value;


}turn ptr2;
}
```

# Other Idea
```
int getDecimalValue(struct ListNode* head){
    int result = 0;
    while(head){
        result = result << 1;
        result += head -> val; 
        head = head -> next;
    }
    return result;
}

```

