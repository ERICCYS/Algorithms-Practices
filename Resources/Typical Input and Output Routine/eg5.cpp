// Variable length per line, without the length given.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans, v;
    char dummy;
    while(1) {
        ans = 0;
        while (scanf("%d%c", &v, &dummy) != EOF) {
            ans += v;
            if (dummy == '\n') {
                break;
            }
        }
        if (feof(stdin)) break;
        printf("%d\n", ans);
    }
}