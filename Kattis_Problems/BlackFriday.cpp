#include<bits/stdc++.h>
using namespace std;

vector<int> r[7];

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        r[a].push_back(i);
    }
    for (int i = 6; i >= 1; i--) {
        if (r[i].size() == 1) {
            printf("%d\n", r[i][0]);
            return 0;
        }
    }
    printf("none\n");
    return 0;
}