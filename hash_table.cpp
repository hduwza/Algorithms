//
// Created by wza on 2019/5/19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define NIL -1
#define KeyType int
#define M 997

typedef struct {
    KeyType key;
} NodeType;

typedef NodeType HashTable[M];

int h(KeyType K) {
    return K % M;
}

int Increment(int i) {
    return i;
}

int Hash(KeyType k, int i) {
    return (h(k) + Increment(i)) % M;
}

int HashSearch(HashTable T, KeyType k, int *pos) {
    int times = 0;
    do {
        *pos = Hash(k, times);
        if (T[*pos].key == k) return 1;
        if (T[*pos].key == NIL) return 0;
    } while (++times && times < M);
    return -1;
}

void HashInsert(HashTable T, NodeType node) {
    int pos, sign;
    sign = HashSearch(T, node.key, &pos);
    if (!sign)
        T[pos] = node;
    else {
        if (sign > 0)
            cout << "duplicate key " << node.key << endl;
        else
            cout << "hash table overflow" << endl;
    }
}

void CreateHashTable(HashTable T, NodeType A[], int n) {
    if (n > M)
        cout << "load factor > 1" << endl;
    for (int i = 0; i < M; ++i) {
        T[i].key = NIL;
    }
    for (int i = 0; i < n; ++i) {
        HashInsert(T, A[i]);
    }
}

int main() {
    int pos;
    HashTable T;
    NodeType node0 = NodeType{3};
    NodeType node1 = NodeType{7};
    NodeType node2 = NodeType{10};
    NodeType node3 = NodeType{13};
    NodeType nodes[] = {node0, node1, node2, node3};
    CreateHashTable(T, nodes, 4);
    cout << HashSearch(T, 10, &pos);
}