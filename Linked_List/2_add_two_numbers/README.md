# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
결과 값을 Reverse할 필요는 없기 때문에, 기초 Addition 연산과 동일하게 각 node의 head부터 연산을 시작.
sum의 max는 19이므로 carry 변수가 필요.
각 Node의 length가 항상 같지 않으므로 두 Node 모두 NULL일 경우 while loop 종료.
결과 노드를 생성하는 function 필요.

# Approach
<!-- Describe your approach to solving the problem. -->
l1과 l2가 NULL이 아닐 경우 각 노드 값을 x,y에 담음. 
Initial carry는 0과 함께 x + y + carry를 sum variable에 할당. 
sum의 modulo를 값으로 하는 새로운 노드를 생성.
노드 이동 
carry의 값 업데이트
l1, l2 노드 이동

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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
```