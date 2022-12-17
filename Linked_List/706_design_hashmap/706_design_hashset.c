#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

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
