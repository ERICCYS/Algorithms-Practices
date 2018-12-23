#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int C;
    cin >> C;
    int results[C] = {0};
    for (int i = 0; i < C; i++) {
        double B[2] = {0};
        cin >> B[0] >> B[1];

        int L;
        cin >> L;
        double Ls[L][2];

        for (int j = 0; j < L; j++) {
            cin >> Ls[j][0] >> Ls[j][1];
        }

        int status = 0;
        for (int j = 0; j < L; j++) {
            if (sqrt((B[0] - Ls[j][0]) * (B[0] - Ls[j][0]) + (B[1] - Ls[j][1]) * (B[1] - Ls[j][1])) <= 8) {
                status = 1;
                break;
            }
        }
        results[i] = status;

    }

    for (int i = 0; i < C; i++) {
        if (results[i] == 1){
            cout << "light a candle" << endl;
        } else {
            cout << "curse the darkness" << endl;
        }

    }
}
