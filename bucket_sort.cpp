//
// Created by wza on 2019/5/19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define n 10

void BUCKET_SORT(double A[]) {
    vector<double> bucket[n];
    for (int i = 0; i < n; ++i) {
        bucket[int(n * A[i])].push_back(A[i]);
    }

    for (int i = 0; i < n; ++i) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < bucket[i].size(); ++j) {
            A[index] = bucket[i][j];
            index++;
        }

    }
}

int main() {
    double num[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    BUCKET_SORT(num);

    for (int i = 0; i < 10; ++i) {
        cout << num[i] << "     ";
    }
}