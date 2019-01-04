#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<pair<int, int>> offers;
    int a, b, t, p;
    double sp;
    while(1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {break;}
        sp = 1000000000000;
        t = 0; p = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if (a > m) {continue;}
            if ((double)b / (double)a < sp || abs((double)b / (double)a - sp) < 0.0001) {
                if (abs((double)b / (double)a - sp) < 0.0001 && a < t) {
                    continue;
                } else {
                    sp = (double)b / (double)a;
                    t = a; p = b;
                }
            }
        }
        if (t != 0 && p != 0) {
            cout << "Buy " << t <<  " tickets for $" << p << endl;
        } else {
            cout << "No suitable tickets offered" << endl;
        }
    }
}