#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

int IntLen (int a){
    int C = 0;

    while (a > 0) {
        C++;
        a /= 10;
    }
    return C;
}


int Min  (int a, int b) {
    return (a >= b) ? b: a;
}


int main() {
    int a;
    int b;


    cin >> a;
    cin >> b;

    int L1 = IntLen(a);
    int L2 = IntLen(b);


//    cout << L1 << "  " << L2 << endl;

    int A[L1] = {0};
    int NA[L1] = {0};
    int B[L2] = {0};
    int NB[L2] = {0};


    FOR (i, 0, L1) {
        A[i] = a % 10;
        a /= 10;
    }

    FOR (i, 0, L2) {
        B[i] = b % 10;
        b /= 10;
    }


//    FOR (i, 0 , L1 - 1) {
//        NA[i] = A[L1 -1 - i];
//    }
//
//    FOR (i, 0 , L2 - 1) {
//        NB[i] = B[L2 - 1 - i];
//    }

    FOR (i, 0, (Min(L1,L2) - 1)) {
        if (A[i] > B[i]) {
            B[i] = 10;
        }
        else if (B[i] > A[i]) {
            A[i] = 10;
        }
    }


//    FOR (i, 0 , L1 - 1) {
//        cout << A[i] << " ";
//    }
//
////    cout << endl;
//
//    FOR (i, 0 , L2 - 1) {
//        cout << B[i] << " ";
//    }
//
    int Ra = 0;
    int Rb = 0;

    int Pa = 0;
    int Pb = 0;

    bool Ya = 1;
    bool Yb = 1;


    FOR (i, 0, L1-1) {
        if (A[i] < 10) {
            Ya = 0;
            int pow = 1;
            FOR (j,0,Pa - 1) {
                pow *= 10;
            }
            Ra += A[i] * pow;
            Pa++;
        }
    }

    FOR (i, 0, L2-1) {
        if (B[i] < 10) {
            Yb = 0;
            int pow = 1;
            FOR (j,0,Pb - 1) {
                pow *= 10;
            }
            Rb += B[i] * pow;
            Pb++;
        }
    }
    if (!Ya)
        cout << Ra << endl;
    else
        cout << "YODA" << endl;

    if (!Yb)
        cout << Rb << endl;
    else
        cout << "YODA" << endl;
    return 0;
}
