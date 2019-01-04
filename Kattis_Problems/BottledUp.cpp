#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, v1, v2;
    scanf("%d %d %d", &s, &v1, &v2);
    int d1, d2;
    d1 = s/v1;
    while(1) {
        if (s - (d1 * v1) == 0) {
            cout << d1 << ' ' << 0 << endl;
            break;
        } else {
            d2 = (s - d1 * v1)/v2;
            if (s - d1 * v1 - d2 * v2 == 0) {
                cout << d1 << ' ' << d2 << endl;
                break;
            } else { 
                if (d1 == 0) {
                    cout << "Impossible" << endl;
                    break;
                } else {
                    d1--;
                    continue;
                }
            }
        }
    }
    return 0;
}