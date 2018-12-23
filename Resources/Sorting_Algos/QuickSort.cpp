#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

void swap(int A[], int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int A[], int low, int high) {
    int pivot = high;
    int small_index = low;
    FOR(i, low, high - 1) {
        if (A[i] <= A[pivot]) {
            swap(A, i, small_index);
            small_index++;
        }
    }
    swap(A, high, small_index);
    return small_index;
}

void QuickSort(int A[], int low,  int high) {
    if (high <= low)
        return ;
    int pi = partition(A, low, high);
    // cout << "low " << low << " high " << high << endl;
    QuickSort(A, low, pi - 1);
    QuickSort(A, pi + 1, high);
}

int main() {
    int A[] = {1,4,2,6,3,78,4,8,7};
    size_t size = (sizeof(A) / sizeof(A[0]));
    QuickSort(A, 0, size - 1);
    FOR(i, 0, size - 1) {
        cout << A[i] << " ";
    }
}