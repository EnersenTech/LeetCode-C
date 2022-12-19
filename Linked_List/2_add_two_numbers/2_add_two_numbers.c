#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* getNewNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode -> val = val;
    newNode -> next = NULL;
    return newNode;
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    unsigned int carry = 0;
    struct ListNode* temp = getNewNode(0);
    struct ListNode* ptr = temp;


    while(l1  !=NULL || l2  != NULL || carry ){
        unsigned int x = l1 ? l1 -> val : 0;
        unsigned int y = l2 ? l2 -> val : 0;

        unsigned int sum;
        sum = x + y + carry;

        ptr -> next = getNewNode(sum % 10);
        ptr = ptr -> next;
        
        carry = sum / 10;

        l1 = l1 ? l1 -> next : NULL;
        l2 = l2 ? l2 -> next: NULL;
    }


    return temp -> next;
}