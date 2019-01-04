#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        list<int> ls;
        ls.push_back(n);
        for (int i = n-1; i > 0; i--) {
            ls.push_front(i);
            for(int j = 0; j < i; j++) {
                int temp = ls.back();
                ls.pop_back();
                ls.push_front(temp);
            }
        }
        for (auto x : ls) {
            printf("%d ", x);
        }
        printf("\n");
    }
}