// example: compute the sum of two numbers
// stops when both number are 0
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b), (a || b)) {
        // stop when both integers are 0
        printf("%d\n", a + b);
    }
}