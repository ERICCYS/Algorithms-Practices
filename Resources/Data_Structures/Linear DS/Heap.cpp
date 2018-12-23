// Heap data structure can be implemented in a range using STL which allows faster input into heap and retrieval of a number always results in the largest number.
// i.e. largest number of the remaining numbers is popped out each time. Other numbers of the heap are arranged depending upon the implementation.

// Operations on heap :

// 1. make_heap() :- This function is used to convert a range in a container to a heap.

// 2. front() :- This function displays the first element of heap which is the maximum number.
// 3. push_heap() :- This function is used to insert elements into heap. The size of the heap is increased by 1. New element is placed appropriately in the heap.

// 4. pop_heap() :- This function is used to delete the maximum element of the heap. The size of heap is decreased by 1. The heap elements are reorganised accordingly after this operation.

// 5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.

// 6. is_heap() :- This function is used to check whether the container is heap or not. Generally, in most implementations, the reverse sorted container is considered as heap. Returns true if container is heap else returns false.

// 7. is_heap_until() :- This function returns the iterator to the position till the container is the heap. Generally, in most implementations, the reverse sorted container is considered as heap.


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    vector <int> v1 = {1,3,5,2,7,6,9};

    make_heap(v1.begin(), v1.end());
    // Note that this "heap" is just a conceputal stuff, delete the item from the heap doesn't mean to delete an item from the vector.

    cout << "The largested value in the heap is: " << endl;
    cout << v1.front() << endl;; 

    v1.push_back(10);
    push_heap(v1.begin(), v1.end());
    cout << "The largested value in the heap is: " << endl;
    cout << v1.front() << endl; 

    pop_heap(v1.begin(), v1.end());
    // Delete the item in the "heap", but the item is still in the vector, it's at the last element
    // We need to pop that value from the heap.
    v1.pop_back();
    cout << "The largested value in the heap is: " << endl;
    cout << v1.front() << endl; 
    
    FOR(i, 0, v1.size() - 1) {
        cout << v1[i] << " ";
    }
    cout << endl;


    // Another method to iterate an vector
    for (int &x : v1) {
        cout << x << " " ;
    }
    cout << endl;

    // Another method to iterate an vector
    for (auto x : v1) {
        cout << x << " " ;
    }
    cout << endl;

    sort_heap(v1.begin(), v1.end());
    // Sort heap will destroy the heap...
    for (auto x : v1) {
        cout << x << " " ;
    }
    cout << endl;


    // is_heap to check if a container is a heap or not.
    is_heap(v1.begin(), v1.end())? 
    cout << "The container is heap " << endl: 
    cout << "The container is not heap" << endl; 

    // using is_heap_until() to check position  
    // till which container is heap 
    auto it = is_heap_until(v1.begin(), v1.end()); 
    
    // Displaying heap range elements 
    cout << "The heap elements in container are : "; 
    for (auto it1 = v1.begin(); it1 != it; it1++) 
       cout << *it1 << " "; 
     
    return 0;



}