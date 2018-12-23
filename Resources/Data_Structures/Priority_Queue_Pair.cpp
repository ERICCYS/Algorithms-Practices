#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
  
// bool compare (pii A, pii B) {
//     return A.first < B.first;
// }  
void showPQ (priority_queue<pii, vector <pii> , greater<pii>> pq) {
    priority_queue <pii, vector <pii> , greater<pii>> pq_copy;
    pq_copy = pq;
    while (!pq_copy.empty()) 
    { 
        cout << pq_copy.top().first << ", " << pq_copy.top().second << endl; 
        pq_copy.pop(); 
    } 
    cout << '\n';  
}

int main () {
    // priority_queue <pii, vector <pii> , less<pii>> pq;
    // This makes a Max priority queue
    priority_queue <pii, vector <pii> , greater<pii>> pq;
    // This makes a Min priority queue

    pq.push(make_pair(0,7));
    pq.push(make_pair(1,9));
    pq.push(make_pair(2,4));
    pq.push(make_pair(1,3));
    pq.push(make_pair(5,2));
    pq.push(make_pair(4,0));
    cout << "The priority queue is : \n"; 
    // while (!pq.empty()) 
    // { 
    //     cout << pq.top().first << ", " << pq.top().second << endl; 
    //     pq.pop(); 
    // } 
    // cout << '\n';  
    showPQ(pq);
}