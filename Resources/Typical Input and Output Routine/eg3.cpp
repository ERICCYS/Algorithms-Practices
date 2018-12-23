// example: compute the sum of two numbers
// stops when EOF
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) == 2) {
        // scanf() returns the number of item read.
        //  Or: while(scanf("%d %d", &a, &b) != EOF)
        printf("%d\n", a + b);
    }
}