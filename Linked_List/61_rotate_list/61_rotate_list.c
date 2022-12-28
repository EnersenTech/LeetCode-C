#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* rotateRight(struct ListNode* head, int k){
    // // Method 1
    // // Rotate = left shift 
    // // length of list = n 
    // // node << n 
    // // by k 
    // // O(N) + O(N)= O(2N)

    // // Method 2
    // // create a new node to store rotated value 
    // // Remove from end 
    // // link a new node with an old one
    // struct ListNode* new_head = NULL;
    // struct ListNode* old_ptr = head;
    // struct ListNode* old_ptr2 = head;
    // struct ListNode* old_tail = head;
    // struct ListNode* old_head = head; 
    // int old_list_length = 0;
    // int index = 0;
    // int quotient;
    

    // while(old_ptr != NULL){
    //     old_list_length++;
    //     old_ptr = old_ptr -> next;
    // }
    // printf("%d \n", old_list_length); // 5
    // // absolute 
    // index = old_list_length - k;
    // if(k == 0 || head == NULL || index == 0) return head;

    // if(index < 0)
    // { 
    //     index = index * -1 + 1; // 1
    //     quotient = k/ old_list_length;
    // }else{
    //     quotient =  old_list_length / k;
    // }

    // printf("index %d \n", index);
    // printf("quotient %d \n", quotient); // 2

    // if(old_list_length == 1 &&  index > 1) return head;
    // if(old_list_length == 1 && quotient > 1) return head;
    
    // if(old_list_length != index){
    //     while(index){
    //         old_ptr2 = old_ptr2 -> next; 
    //         index--;
    //     }
    // }
    // if(old_list_length != quotient) {
    //     while(quotient){
    //         old_tail = old_tail -> next;
    //         quotient--;
    //     }
    // }
    // // Replace old list tail to NULL
    // if(old_tail != NULL){
    //     old_tail -> next = NULL;
    // }else{
    //     printf("old_tail %d \n", old_tail -> val);
    //     old_tail = NULL;
    // }
    // // old_tail = old_tail != NULL ? old_tail -> next = NULL : old_tail = NULL; 
    // // old_tail -> next = NULL;
    // // printf("%d ", old_tail -> val); // 3 0
    // printf("%d ", old_ptr2 -> val); // 4 1
    // new_head = old_ptr2; // 4 5 2

    // printf("--------------------\n");

    // if(new_head == NULL ) return head;
    // struct ListNode* new_ptr = new_head; 
    // while(new_ptr  -> next != NULL){
    //     new_ptr = new_ptr -> next;
    // }
    // new_ptr -> next = old_head;
    
    // return new_head;

    if(head == NULL || head->next == NULL)   return head;
    else{
        struct ListNode *prev = NULL;
        struct ListNode *temp = NULL;
        temp = head;
        int c = 0;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        k %= c;
    temp = head;
    while(k-- > 0){
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        temp->next = head;
        prev->next = NULL;
        head = temp;
        temp = head;
    }
    return head;
    }
}