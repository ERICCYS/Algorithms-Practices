#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592654

int main() {
    int C;
    cin >> C;
    double result[C] = {0.0};
    for (int j = 0; j < C; j++) {
        int r, n;
        cin >> r >> n;
        int v[n][2] = {{0,0}};
        for (int i = 0; i < n; i++) {
            cin >> v[i][0] >> v[i][1];
        }
        double len = 0;
        for (int i = 0; i < n - 1; i++) {
            len += sqrt((v[i + 1][0] - v[i][0]) * (v[i + 1][0] - v[i][0]) + (v[i + 1][1] - v[i][1]) * (v[i + 1][1] - v[i][1]));
        }
        len += sqrt((v[0][0] - v[n - 1][0]) * (v[0][0] - v[n - 1][0]) + (v[0][1] - v[n - 1][1]) * (v[0][1] - v[n - 1][1]));
        double slen = len - (2 * PI * r);
        if (slen < 0) {
            result[j] = -1;
        } else {
            result[j] = slen / len;
        }
    }

    for (int j = 0; j < C; j++) {
        if (result[j] >= 0) {
            cout << result[j] << endl;
        } else {
            cout << "Not possible" << endl;
        }
    }
}
