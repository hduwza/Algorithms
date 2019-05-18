//
// Created by wza on 2019/5/17.
//
#include <iostream>
#include <algorithm>

using namespace std;

#define n 8


int length(int *A) {
    return sizeof(A) / sizeof(int);
}

int get_max(int *A) {
    int max = A[0];
    for (int i = 1; i < length(A); ++i) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void COUNT_SORT(int *A, int exp) {
    int array[n];
    int buckets[10] = {0};

    for (int i = 0; i < n; ++i) {
        buckets[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        buckets[i] += buckets[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        array[buckets[(A[i] / exp) % 10] - 1] = A[i];
        buckets[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        A[i] = array[i];
    }
}

void RADIX_SORT(int *A) {
    int max = get_max(A);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        COUNT_SORT(A, exp);
    }
}

int main() {
    int num[] = {2, 5, 3, 0, 2, 3, 0, 3};
    RADIX_SORT(num);

    for (int i = 0; i < n; ++i) {
        cout << num[i] << "     ";
    }
}