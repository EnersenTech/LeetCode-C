#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* ptr = head;
    struct ListNode* pair = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* result = NULL;

    if(head == NULL){
        return head;
    }else{
        result = head -> next;
    }

    while(ptr != NULL){
        if(ptr -> next == NULL){
            return ptr;
        }
        pair = ptr -> next; 
        temp = pair -> next;

        // Swap 
        pair -> next = ptr;
        // further linking 
        if(temp != NULL){
            if(temp -> next != NULL){
                ptr -> next = temp ->next;
            }else{
                ptr -> next = temp;
                break;
            }
        }else{
            ptr -> next = temp; 
        }
        ptr = temp;
    }
    return result;
}