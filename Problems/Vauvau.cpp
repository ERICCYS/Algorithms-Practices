#include <iostream>
using namespace std;
int main() {
    int A, B, C, D;
    int P, M, G;

    int Pc, Mc, Gc;
    Pc = 0;
    Mc = 0;
    Gc = 0;

    cin >> A >> B >> C >> D;

    cin >> P >> M >> G;

    if (P % (A + B) <= A && P % (A + B) > 0) {
        Pc++;
    }

    if (P % (C + D) <= C && P % (C + D) > 0) {
        Pc++;
    }

    if (M % (A + B) <= A && M % (A + B) > 0) {
        Mc++;
    }

    if (M % (C + D) <= C && M % (C + D) > 0) {
        Mc++;
    }

    if (G % (A + B) <= A && G % (A + B) > 0) {
        Gc++;
    }

    if (G % (C + D) <= C && G % (C + D) > 0) {
        Gc++;
    }

    cout << ((Pc == 0) ? "none" : (Pc == 1) ? "one" : "both") << endl;
    cout << ((Mc == 0) ? "none" : (Mc == 1) ? "one" : "both") << endl;
    cout << ((Gc == 0) ? "none" : (Gc == 1) ? "one" : "both") << endl;
}
