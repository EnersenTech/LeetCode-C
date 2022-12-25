# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
처음 pair를 swap하고 다음 pair과 link한 다음
다음 pair도 swap하면 될 것이라고 생각하고 시작했다.
[1,2,3,4] = [2,1]->[3,4] = [2,1] -> [4,3] 
그러나 처음 pair를 swap한 뒤, link를 next로 진행하니 당연하게 문제가 발생했다.
next는 다음 pair swap 시, 적절한 Link address가 아니기 때문이다. 
그래서 다음 pair가 swap할 것을 예상하고, swap 이후의 pair와 link를 하도록 문제를 풀었다.

# Approach
<!-- Describe your approach to solving the problem. -->
    // current = head
    // if current != NULL
    // fast = head -> next
    // swap 
        // temp = fast -> next
        // curret -> next = fast 
        // fast -> next = current 
        // current = temp 
        // while(current != NULL)
    
    // Problem encountered
    // [1,2] -> [2,1] ok 
    // [1,2,3,4] -> [2,1] [4,3] lost link
    // [2,1,3,4] [1,3000] -> [3,4000] -> [4,NULL]  
    // [1,3000] -> [3,NULL] -> [4,3000]
    // [2,1] [4,3]
    // Have to update current -> next to current -> next -> next
    // [2,1,3,4] [1,4000] -> [3, NULL] -> [4,3000]
    
    // Check if fast has next value 
    // if fast -> next
    // current -> next = fast -> next
    // else
    // current -> next = fast 
    
    // Linked done when the total node sum is even 

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    // if head != NULL
    // if head -> next != NULL 
    // pair = head -> next; 
    // head -> val = pair -> val 
    // pair -> val = head -> val 
    // head = pair -> next; 
    // while(head != NULL)

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
            printf("bb");
            return ptr;
        }
        pair = ptr -> next; // 2000 4000
        printf("aa");
        temp = pair -> next; // 3000 NULL

        // Swap 
        pair -> next = ptr; // 3000 -> 1000 4000 -> 3000
        // ptr -> next = temp; // 2000 -> 3000 4000 -> NULL

        // further linking 
        // [2,1,3,4] 상태. 여기서 ptr -> next가 3000인데 이걸 4000으로 바꿔야함. 
        if(temp != NULL){
            // temp != NULL은 temp -> next가 무조건 있다는 뜻이다. 
            printf("%d ", temp -> val);
            if(temp -> next != NULL){
                    printf("cc");

                ptr -> next = temp ->next;
            }else{
                            printf("ee");

                ptr -> next = temp;
                break;

            }
            // ptr -> next = temp -> next; // 4000이 됨. 
        }else{
                    printf("rr");

            ptr -> next = temp; // 3000이 됨. 

        }

        
        ptr = temp; // 3000 NULL
    }

    return result;
}

// head = pair? 2000
// 2000 -> 1000 
// head = ?
// ptr 때문에 head가 바뀌었다? ptr = 1000 이었고 head = 1000이다. 
// ptr -> next = 3000으로 갔으니 1000 = [1, 3000] 이렇게 되지. 
// 다시 ptr -> next = NULL로 갔으니 1000 = [1, NULL] 이렇게 되지. 
// ptr NULL 이렇게 했네. 
// 1000 =  NULL 이렇게 되었다.  

// 1000 = [1, 2000]     [1]
// 2000 = [2, 3000]     [1,2]
// 3000 = [3, 4000]     [1,2,3]
// 4000 = [4, NULL]     [1,2,3,4]

// 1000 = [1, 3000]     [1]
// 2000 = [2, 1000]     [2,1]

// 3000 = [3, NULL]     [2,1,3]
// 4000 = [4, 3000]     ???

// 1000 = [1, 4000] Needed

// 다시 생각해 봐야겠다. 

// 단순히 1 -> 2 2 -> 1 이렇게 하면 안 되겠다. 
// 끊어서?
// swap swap link 근데 이게 [1,2,3]이면? swap 할 필요가 없잖아. 
// Recursion을 사용하고 싶지 않은데?
// 

// 아직 바뀌기 전에 어떻게 하면 좋을까?
// 3000 = [3, 4000]     [1,2,3]
// 4000 = [4, NULL]     [1,2,3,4]
// [2,1,3,4] 이 상태인데
// ptr = 3000이고 
// 흐음. 
// 2,1,3,4 인 상태에서 


// 만약 4000이 있다면, [2,1,4] 이렇게 Linking 1000 = [1, 4000]
// 만약 4000이 없다면, [2,1,3,4] 이렇게 Linking 1000 = [1,3000]
// 그 다음에 진행하는데, ptr -> next 즉, 3000의 next가 NULL이면, 홀수라는 뜻이잖아. 
// 그럼 Swap을 하지 않고 Linking 된 상태로 return해야지.

```