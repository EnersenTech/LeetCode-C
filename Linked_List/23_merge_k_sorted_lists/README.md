# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
21번 문제에서 풀었던 "Merge Two Sorted Lists"가 생각났다. 
Array Loop를 돌면서, Merge를 하면 최종적인 1개의 List가 나올 것이라고 생각하고 진행했다.

다만, 이렇게 풀 경우 새로운 아이디어를 생각하지 않는 것 같아, 다른 방식도 연구해 보았다. 
Array Loop를 돌면서 unsorted Linked List를 생성하고 마지막에 sort method를 사용해도 되지 않을까 
생각해서 unsorted Linked List를 생성했는데, 문제는 Array list가 NULL일 경우 linking 문제가 존재하여 
Test case 133개 중  120개만 통과했다. 
Debugging을 했지만, 그럴 수록 코드가 더러워지는 것이 느껴져서 해당 방법으로 풀면 좋지 않다고 여겨 다시 첫 번째 방법으로 돌아갔다. 

# Approach
<!-- Describe your approach to solving the problem. -->
Divide & Conquer 
Loop를 돌면서 이전 list와 다음 list를 Merge해서 1개의 결과를 낸다. 
Recursion 사용

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

$$O(n * K * LogK)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n*K)$$
# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeList(struct ListNode* list1, struct ListNode* list2){
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


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    struct ListNode  *new_head = NULL;
    
    for(int i=0;i<listsSize;i++){
        new_head = mergeList(new_head,lists[i]);
    }
    
    return new_head;
}
```

# Trial Code (120 out of 133)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void sortList(struct ListNode* head){
    struct ListNode* current = head, *index = NULL;
    int temp; 

    if(head == NULL) return;
    while(current != NULL){
        index = current -> next;
        while(index != NULL){
            if(current -> val > index -> val){
                temp = current -> val;
                current -> val = index -> val; 
                index -> val = temp;
            }
            index = index -> next;
        }
        current = current -> next;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(lists == NULL || listsSize == 0) return NULL;
    struct ListNode* tail = NULL;

    struct ListNode* ptr = NULL;
    int i = 0;

    while(i < listsSize){
        if(lists[i] == NULL){
            i++;
        }
        else{
            if(tail != NULL){
                struct ListNode* head = lists[i];
                printf("lists[1] %d ", head -> val);
                tail -> next = head; 
                while(head -> next != NULL){
                    head = head -> next; 
                }
                tail = head;
                i++;
            }else{
            struct ListNode* head = lists[i];
                while(head -> next != NULL){
                    head = head -> next; 
                }
                tail = head; 
                i++;
            }
        }
    }

    if(ptr == NULL){
        ptr = lists[0];
    }

    sortList(ptr);

    return ptr;
}
```
