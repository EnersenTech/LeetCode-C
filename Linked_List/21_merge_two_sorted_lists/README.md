# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
각 list value를 비교하여 새로운 struct에 push하면 되겠다고 생각했다. 
그러나 Push function을 새로 만드는 것 보다는, 단순히 linking을 통해 푸는 것이 효율적이라고 판단했다. 
value를 비교하여 새로운 list의 next 값으로 chaining하는 과정은 오래걸리지 않았다. 
다만, value를 비교하기 위해 pointer -> next != NULL이 보장되어야 했으며
pointer -> next를 보장하기 위해서 pointer != NULL이 보장되어야 했다. 
중간 Iteration 과정에서 NULL pointer Error가 발생하여 while base condition을 or 에서 and로 변경하여 
진행하였다.

# Approach
<!-- Describe your approach to solving the problem. -->
1. If both empty lists, return empty list. 
2. Loop over until one of list reaches the end with merging
3. Chain with left element link 

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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL && list2  == NULL) return NULL;

    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ptr = list3;

    while(list1 && list2){
        if(list1 -> val <= list2 -> val){
            ptr -> next = list1; 
            list1 = list1 -> next;
            ptr = ptr -> next;
        }else{
            ptr -> next = list2; 
            list2 = list2 -> next;
            ptr = ptr -> next;
        }
    }
    if(list1){
        ptr -> next = list1;
    }
    if(list2){
        ptr -> next = list2;
    }

    return list3->next;
}
// red 1 -> blue 1 -> red 2 -> blue 3 -> red 4 -> blue 4 last Node
```