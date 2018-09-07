#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string S;
    cin >> S;

    int E = S.length();
    int Max = (int)pow(2,E);
    int x = 0;
    int y = 0;

    for (int i = 0; i < E; i++) {
        if (S[i] == '1') {
            x += Max / 2;
        }
        if (S[i] == '2') {
            y += Max / 2;
        }
        if (S[i] == '3') {
            x += Max / 2;
            y += Max / 2;
        }
        Max /= 2;
    }
    cout << S.length() << " " << x << " " << y << endl;
    return 0;
}
