#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int A[10]; // 10 is the size of the array we want to sort.

int main() {
    int max_value = 0;
    for(int i = 0; i < 10; i++) {
        cin >> A[i];
        max_value = max(max_value, A[i]);
    }
    int min_size = max_value + 1;
    int B[10];
    int C[100]; // The size of C should be the max_value + 1, given all the number is non negative.
    memset(C, 0, sizeof(C[0]) * 100);

    for (int i = 0; i < 10; i++) {
        C[A[i]]++; // Count the number of elememts that is equal to this element.
    }

    for (int i = 0; i < 100; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < 100; i++) {
        C[i] += C[i - 1]; //Compute the number of elements that is greater than or equal to this element.
    }
    
    for(int i = 9; i >= 0; i--) {
        C[A[i]] = C[A[i]] - 1; // Reduce the number of elements greater than or equal that this element by one, this is the index of this element in the sorted array.
        cout << "Putting " << A[i] << " into index " << C[A[i]] << endl;
        B[C[A[i]]] = A[i]; // In the sorted array, C[A[i]] should be the correct position of the A[i]
    }

    // B is the sorted arrary.

    for(int i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
    cout << endl;


    
}