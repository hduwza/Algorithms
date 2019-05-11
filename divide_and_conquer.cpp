#include <iostream>

#define N 1009
using namespace std;

void MERGE(int *array, int p, int q, int r) {
    int i, j;
    int sort_array[r - p + 1];
    int index = 0;
    for (i = p, j = q + 1; i <= q && j <= r;) {
        if (array[i] < array[j]) {
            sort_array[index++] = array[i++];
        } else {
            sort_array[index++] = array[j++];
        }
    }

    while (i <= q)
        sort_array[index++] = array[i++];
    while (j <= r)
        sort_array[index++] = array[j++];


    for (int i = 0; i < index; ++i) {
        array[p + i] = sort_array[i];
    }

}

void MERGE_SORT(int *array, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MERGE_SORT(array, p, q);
        MERGE_SORT(array, q + 1, r);
        MERGE(array, p, q, r);
    }
}

int main() {
    int array[N];
    int index = 0;
    int num;
    int times;
    cin >> times;
    while ((index < times) && (cin >> num)) {          // 顺序不能换， 前边为0才会立即停止
        array[index++] = num;
    }
    MERGE_SORT(array, 0, --index);

    for (int i = 0; i <= index; ++i) {
        cout << array[i] << endl;
    }
}