#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)

bool compare(int N, int M) {
    return N > M;
}

int main() {
    int T;
    cin >> T;
    string S;
    vector <int> SG;
    vector <int> SM;
    while(T--) {
        getline(cin, S);
        int G, M;
        int sg, sm;
        cin >> G >> M;
        SG.clear();
        SM.clear();
        
        FOR(i, 0, G - 1) {
            cin >> sg;
            SG.push_back(sg);
        }
        FOR(i, 0, M - 1) {
            cin >> sm;
            SM.push_back(sm);
        }

        sort(SG.begin(), SG.end(), compare);
        sort(SM.begin(), SM.end(), compare);

        // FOR(i, 0, G - 1) {
        //     cout << SG[i] << " ";
        // }
        // cout << endl;

        // FOR(i, 0, M - 1) {
        //     cout << SM[i] << " ";
        // }
        // cout << endl;
        int dead_G = 0, dead_M = 0;
        while (dead_G < G && dead_M < M) {
            if (*SG.rbegin() < *SM.rbegin()) {
                dead_G++;
                SG.pop_back();
            }
            else {
                dead_M++;
                SM.pop_back();
            }
        }
        if (dead_G == G)
            cout << "MechaGodzilla" << endl;
        else
            cout << "Godzilla" << endl;
    }

    return 0;
}