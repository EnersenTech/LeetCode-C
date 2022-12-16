# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Iteration 중 순서를 바꾸기 위해서, 저장해야 하는 값이 많은 것으로 판단하여 link pointer를 선언하였다. 
Head에서 시작하여 다음 node의 address를 담고, 현재 node의 link address를 바꾸기 위한 값도 필요할 것이며, 
현재 node의 address를 담을 총 3개의 변수가 있으면 될 것이라고 판단했다.


# Approach
<!-- Describe your approach to solving the problem. -->
Current = head;
Prev = NULL;
Forward = NULL;

[1,2,3,4,5]
1 -> 2 -> 3 -> 4 -> 5

1. Set forward 
Forward = 2 

2. Change current link to prev (Swap)
Current -> next = NULL

3. Increment prev value to current
Prev = Current = 1 

4. Increment current value to forward
Current = Forward = 2

Loop over the list till current equals NULL


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(N)$$, As we are traversing the list only once.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$ , As constant extra space is used.

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* current = head; 
    struct ListNode* prev = NULL;
    struct ListNode* forward = NULL;

    while(current != NULL){
        forward = current -> next; 
        current -> next = prev;
        prev = current;
        current = forward;
    }
    return prev; 

}
```

