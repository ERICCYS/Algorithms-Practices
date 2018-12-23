// Priority queues are a type of container adapters, specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non decreasing order(hence we can see that each element of the queue has a priority{fixed order}).
 
// The functions associated with priority queue are:
// empty() – Returns whether the queue is empty
// size() – Returns the size of the queue
// top() – Returns a reference to the top most element of the queue
// push(g) – Adds the element ‘g’ at the end of the queue
// pop() – Deletes the first element of the queue

#include <iostream>
#include <queue> 
  
using namespace std; 
  
void showpq(priority_queue <int> gq) 
{ 
    priority_queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << " " << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    priority_queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(30); 
    gquiz.push(20); 
    gquiz.push(5); 
    gquiz.push(1); 
  
    cout << "The priority queue gquiz is : "; 
    showpq(gquiz); 
  
    cout << "gquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.top() : " << gquiz.top(); 
  
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showpq(gquiz); 
  
    return 0; 
}
