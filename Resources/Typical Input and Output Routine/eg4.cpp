// Variables number of inputs per line given the numebr of item this line
#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, ans, v;
    while(scanf("%d", &k) != EOF) {
        ans = 0;
        while(k--) {
            scanf("%d", &v);
            ans += v;
        }
        printf("%d\n", ans);
    }   
}