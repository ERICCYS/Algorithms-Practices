// Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end and (top) an element is removed from that end only.
 
// The functions associated with stack are:
// empty() – Returns whether the stack is empty – Time Complexity : O(1)
// size() – Returns the size of the stack – Time Complexity : O(1)
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
// pop() – Deletes the top most element of the stack – Time Complexity : O(1)

// C++ STL stack

#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    cout << "The stack is: ";
    showstack(s);

    cout << "\ns.size(): " << s.size();

    cout << "\ns.top(): " << s.top();

    s.pop();
    cout << "\nThe stack is: ";
    showstack(s);


    cout << "\nCopy a stack: " << endl;
    stack <int> s1 = s;
    showstack(s1);
    return 0;
}