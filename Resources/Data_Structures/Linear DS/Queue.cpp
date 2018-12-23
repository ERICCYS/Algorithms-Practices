// empty() – Returns whether the queue is empty
// size() – Returns the size of the queue
// front() – Returns a reference to the first element of the queue
// back() – Returns a reference to the last element of the queue
// push(g) – Adds the element ‘g’ at the end of the queue
// pop() – Deletes the first element of the queue

// C++ STL Queue

#include <iostream>
#include <queue>

using namespace std;

void showq(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

}

int main() {
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "The queue is: ";
    showq(q);

    cout << "q.front(): " << q.front() << endl;
    cout << "q.back(): " << q.back() << endl;
    cout << "q.size(): " << q.size() << endl;

    cout << "q.pop(): " << endl;
    q.pop();
    cout << "The queue is: ";
    showq(q);

    cout << "Copy a queue: " << endl;
    queue <int> q1 = q;
    cout << "The queue is: ";
    showq(q1);
    return 0;
}