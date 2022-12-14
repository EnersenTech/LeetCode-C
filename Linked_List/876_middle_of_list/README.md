# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음 생각한 것은 list의 전체 길이를 구한 뒤
Even & Odd의 경우의 수를 토대로 중간 값을 구하는 것이었다. 

그러나 length를 구하기 위해 Iteration하는 Time Complexity가 $$O(N)$$ 이 추가적으로 발생하므로 다른 방법을 생각해 보기로 했다.

다음으로 떠올린 것은 Auxilian Space를 사용하더라도, Time Complexity를 줄이고자 하는 방법이었다. 
# Approach
<!-- Describe your approach to solving the problem. -->
head pointer를 지니는 2개의 변수를 설정하여, 1개는 1씩 Increment하고 
나머지 한 개는 2 만큼 Increment한다. 
만약 2씩 Increment하는 pointer가 중간에 NULL로 바뀌거나 혹은 마지막 element에 다다른 다면, 1씩 증가한 변수가 중간 값이 된다. 


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
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head; 

    while(ptr1 != NULL && ptr1 -> next != NULL){
        ptr1 = ptr1 -> next -> next;
        ptr2 = ptr2 -> next;
    }
    return ptr2;
}
```

