//
// Created by wza on 2019/5/15.
//
#include <iostream>
using namespace std;

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i )
#define RIGHT(i)  (2 * i + 1)

typedef struct {
    int *nodes;
    int length;
    int heap_size;
} heap, *heap_node;

void MAX_HEAPIFY(heap_node A, int i) {
    int left, right, largest, temp;
    while(1) {
        left  = LEFT(i);
        right = RIGHT(i);

        if (left < A->heap_size && A->nodes[left] > A->nodes[i])
            largest = left;
        else
            largest = i;

        if (right < A->heap_size && A->nodes[right] > A->nodes[largest])
            largest = right;

        if (largest == i)
            return;

        temp = A->nodes[i];
        A->nodes[i] = A->nodes[largest];
        A->nodes[largest] = temp;

        i = largest;
    }
}

void BUILD_MAX_HEAP(heap_node A) {
    for (int i = (A->heap_size-1) / 2; i >= 0; --i) {
        MAX_HEAPIFY(A, i);
    }

}

void HEAPSORT(heap_node A) {
    BUILD_MAX_HEAP(A);


    int temp;
    for (int i = A->length-1; i > 0; --i) {



        //exchange A[i] and A[1]
        temp = A->nodes[i];
        A->nodes[i] = A->nodes[0];
        A->nodes[0] = temp;

        A->heap_size--;
        MAX_HEAPIFY(A, 0);




    }
    A->heap_size = A->length;
}

int main() {

    int num[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap_node A = new heap {num, 10, 10};
//    A->nodes = num;
//    A->length = A->heap_size = 10;
    HEAPSORT(A);
    for (int i = 0; i < 10; ++i) {
        cout << A->nodes[i] << "   ";
    }



}