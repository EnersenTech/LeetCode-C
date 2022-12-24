#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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