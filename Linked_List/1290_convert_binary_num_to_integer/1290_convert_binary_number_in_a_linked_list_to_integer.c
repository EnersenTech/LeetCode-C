#include<stdlib.h>
#include<math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
int getDecimalValue(struct ListNode* head){
    int decimal_value = 0;
    int node_len = 0;
    struct ListNode* ptr = head; 
    while(ptr != NULL){
        node_len++;
        ptr = ptr -> next;
    }
    while(head  != NULL){
        node_len--;
        decimal_value += head -> val * pow(2, node_len);
        head = head -> next;
    }
    return decimal_value;
}