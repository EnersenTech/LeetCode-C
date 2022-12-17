# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Hash Set을 Design하기 위해 우선 Initialize를 통해 Key 보다 큰 Hash Table 만든다.
add 되면, value = 1 (true)
remove 되면, value = 0 (false)
memory free하면 free NULL
contains는 indexing을 통해 찾는다. 

# Approach
<!-- Describe your approach to solving the problem. -->
처음에는 Table MAX size를 malloc으로 init했을 때, 임의의 값이 pointer에 저장되어 원하는 결과가 나오지 않았다. 
따라서 Calloc을 통해 Hash되지 않은 Index의 value를 0으로 모두 초기화 했다. 

단순히 Hash set을 만들어서 제한된 operations을 진행하므로 Collision을 고려하지 않았다. 
만약 Collision을 고려하며, 주제인 Linked List를 사용해야 한다면, Chaining을 통해 값을 loop up 하는 기능이 필요할 것으로 보인다. 


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(1)

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1)
# Code
```

typedef struct {
    uint8_t val[1000001];
} MyHashSet;


MyHashSet* myHashSetCreate() {
    // MyHashSet * result = (MyHashSet *)malloc(sizeof(MyHashSet));
    MyHashSet * result = calloc(1, sizeof(MyHashSet));
    return result;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj -> val[key] = 1;
  
}

void myHashSetRemove(MyHashSet* obj, int key) {
  obj -> val[key] = 0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj -> val[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
```