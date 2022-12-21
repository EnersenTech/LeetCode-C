# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Singly Linked List에서 index가 주어졌을 때, 삭제하는 수단은 O(N)을 요구한다. 
n-1 element의 link를 n+1 혹은 NULL로 바꿔야 하기 때문에 단순하게 진행하기로 했다. 
뒤에서 부터 n번째 element가 주어졌으므로, total length에서 n을 빼서 index를 구한 뒤 
나머지는 일반적 삭제를 실행했다. 

# Approach
<!-- Describe your approach to solving the problem. -->
1. Find a length of list 
2. Find a index ptr 
3. Update list 

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* traverse_ptr = head;
    struct ListNode* index_ptr = head;
    int length = 0;
    int index;
    // Find tail Node
    while(traverse_ptr != NULL){
        traverse_ptr = traverse_ptr -> next;
        length++;
    }
    index = length - n;
    if(index <= 0){
        return head -> next;
    }
    while(--index){
        index_ptr = index_ptr -> next;   
    }
    if(index_ptr -> next != NULL){
        index_ptr -> next = index_ptr -> next -> next;
    }else{
        index_ptr -> next = index_ptr -> next;
    }
    return head;
}
```

# Other Idea 
임의의 조건이 지저분 하기도 하고, 삭제한 memory를 free하지도 않아서 
좀 더 나은 방법이 있는지 확인해 보았다. 
비용 자체는 동일하지만, 직관적인 코드 구현 및 조건을 최소화한 코드가 있어 첨부한다.
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    for(int i=0; i<n; i++) fast = fast->next;
    if(!fast) return head->next;
    
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode* q = slow->next;
    slow->next = slow->next->next;
    free(q);
    
    return head;
}
```