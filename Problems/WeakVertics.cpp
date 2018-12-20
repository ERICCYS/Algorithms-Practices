#include<bits/stdc++.h>
using namespace std;

int main() {
    int AM[20][20];
    int n;
    while (cin >> n && n != -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> AM[i][j];
            }
        }
        bool weak;
        vector<int> U;
        for (int i = 0; i < n; i++) {
            weak = true;
            U.clear();
            for (int j = 0; j < n; j++) {
                if (AM[i][j] == 1) {
                    U.push_back(j);
                }
            }
            if (U.size() < 2) {
                cout << i << " ";
                continue;
            } else {
                for (int a = 0; a < U.size()-1; a++) {
                    for (int b = a+1; b < U.size(); b++) {
                        if (AM[U[a]][U[b]] == 1) {
                            weak = false;
                            break;
                        }
                    }
                    if (!weak) {
                        break;
                    }
                }
                if (weak) {
                    cout << i << " ";
                }
            }
        }
        cout << endl;
    }
}