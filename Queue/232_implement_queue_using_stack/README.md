# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Circular Array를 이용하여 Queue implement.

# Approach
<!-- Describe your approach to solving the problem. -->
myQueueCreate() 
-> inserted at the rear end  = capacity - 1 
-> poped at the front end = 0 
-> if enqueued increment the size, else if dequeued decrement
-> create an data array

myQueuePush()
-> Enqueue
-> push data into array at rear position
-> Increment size 

myQueuePoP()
-> Dequeue
-> pop data from array at front position
-> Decrement size

myQueuePeek()
-> front

myQueueEmpty()
-> if size == 0, then queue is empty



# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(1)$$ 

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$ 

# Code
```
#define MAX_QUEUE_SIZE 100

typedef struct {
    int front,rear,size;
    unsigned long capacity;
    int* array;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue -> front = queue -> size = 0;

    queue -> capacity = MAX_QUEUE_SIZE;
    
    queue -> rear = MAX_QUEUE_SIZE - 1;

    queue -> array = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));

    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj -> rear = (obj -> rear + 1 )% obj -> capacity;
    obj -> array[obj -> rear] = x;
    obj -> size = obj -> size + 1;  
}

int myQueuePop(MyQueue* obj) {
    int item = obj -> array[obj -> front];
    obj -> front = (obj -> front + 1) % obj -> capacity;
    obj -> size = obj -> size - 1;
    return item;
}

int myQueuePeek(MyQueue* obj) {
    return obj -> array[obj -> front];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj -> size == 0);
}

void myQueueFree(MyQueue* obj) {
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```