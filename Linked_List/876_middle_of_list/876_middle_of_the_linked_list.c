#include <stdlib.h>
#include <stdio.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* ptr1 = head; // Fast Node
    struct ListNode* ptr2 = head; // Slow Node 

    while(ptr1 != NULL && ptr1 -> next != NULL){
        ptr1 = ptr1 -> next -> next; 
        ptr2 = ptr2 -> next; 
    }
    return ptr2;
}
