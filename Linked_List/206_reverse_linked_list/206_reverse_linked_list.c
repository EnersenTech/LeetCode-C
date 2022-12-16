#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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