#include<bits/stdc++.h>
#define PI 3.141592654
using namespace std;

int main() {
    int des;
    cin >> des;
    string results[10000] = {"\0"};
    int totalQ = 0;
    int index = 0;


    for (int i = 0; i < des; i++) {
        int dro;
        cin >> dro;

        double D[dro][3] = {{0.0,0.0,0.0}};
        string C[dro] = {"\0"};
        // D[][0] = x; D[][1] = y; D[][2] = V;

        for (int i = 0; i < dro; i++) {
            cin >> D[i][0] >> D[i][1] >> D[i][2] >> C[i];
        }

        int Q;
        cin >> Q;
        totalQ += Q;
        double query[Q][2] = {{0.0,0.0}};
        for (int i = 0; i < Q; i++) {
            cin >> query[i][0] >> query[i][1];
        }

        for (int i = 0; i < Q; i++) {
            string result;
            double dis;
            double rid;
            int looking = 1;
            for (int j = dro - 1; j >= 0; j--) {
                dis = sqrt((query[i][0] - D[j][0]) * (query[i][0] - D[j][0]) +  (query[i][1] - D[j][1]) * (query[i][1] - D[j][1]));
                rid = sqrt(D[j][2] / PI);
                if (dis < rid) {
                    result = C[j];
                    results[index] = result;
                    index++;
                    looking = 0;
                    break;
                }
            }
            if (looking == 1) {
                result = "white";
                results[index] = result;
                index++;
            }
        }

    }


    for (int i = 0; i < totalQ; i++) {
        cout << results[i] << endl;
    }
    return 0;
}
