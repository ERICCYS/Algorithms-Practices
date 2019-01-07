#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a) > (b)) ? (a) : (b)
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int a = 1, b = 1;
    cin >> a >> b;
    while (a != 0 || b != 0) {


        int A[a] = {0};
        int B[b] = {0};
        int c = 0;

        FOR (i, 0, a - 1) {
            cin >> A[i];
        }
        FOR (i, 0, b - 1) {
            cin >> B[i];
        }

        sort (A, A + a);
        sort (B, B + b);

        int i = 0, j = 0;
        for (i = 0, j = 0; (i < a) && (j < b); ) {
            if (A[i] == B[j]) {
//                cout << A[i] << " = " << B[j] << endl;
                c++;
                i++;
                j++;
            }
            else if (A[i] > B[j]) {
//                cout << A[i] << " > " << B[j] << endl;
                j++;
            }
            else{
//                cout << A[i] << " < " << B[j] << endl;
                i++;
            }
        }
        cout << c << endl;
        cin >> a >> b;
    }
}
