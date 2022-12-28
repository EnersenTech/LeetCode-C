#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head){
    // if head != NULL
    // iterate list 
    // initial value 
    // if value == next 
    // remove next & store next next (1,3000) temp = 3000 
    // if temp == NULL -> last node = remove and return head
    // if temp != NULL -> remove and loop over 
    // head = head -> next 

    // How to remove?
    // store temp and link to temp, free location
    ////////////////////////////////////////////////////
    struct ListNode* ptr = head; 
    struct ListNode* temp = NULL;
    int initial_value, next_value = NULL;
    while(ptr != NULL && ptr -> next != NULL){
        // Store next node ptr
        temp = ptr -> next;
        
        // Comp prev with next 
        initial_value = ptr -> val;
        next_value = temp -> val;

        // Remove duplicate
        if(initial_value == next_value){
            ptr -> next = temp -> next;
            free(temp);
        }else{
            ptr = ptr -> next;
        }
    }
    return head;
}