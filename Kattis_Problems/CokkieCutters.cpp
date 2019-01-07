#include<bits/stdc++.h>
using namespace std;
double PGArea (double[][2],int N);
int main () {
    int N;
    cin >> N;
    double V[N][2] = {{0,0}};
    for (int i = 0; i < N; i++) {
        cin >> V[i][0] >> V[i][1];
    }

    int A;
    cin >> A;
    double F = sqrt(A / PGArea(V,N));

    double xmin = V[0][0];
    double ymin = V[0][1];
    for (int i = 0; i < N; i++) {
        if (V[i][0] < xmin) {
            xmin = V[i][0];
        }
        if (V[i][1] < ymin) {
            ymin = V[i][1];
        }
    }

    for (int i = 0; i < N; i++) {
        V[i][0] -= xmin;
        V[i][1] -= ymin;
    }

    for (int i = 0; i < N; i++) {
        V[i][0] *= F;
        V[i][1] *= F;
    }

    for (int i = 0; i < N; i++) {
        if (abs(V[i][0] - (int)V[i][0]) < 0.00001 && abs(V[i][1] - (int)V[i][1]) < 0.00001) {
            cout << V[i][0] << ".0" << " " << V[i][1] << ".0" << endl;
        }
        else if (abs(V[i][0] - (int)V[i][0]) < 0.00001) {
            cout << V[i][0] << ".0" << " " << V[i][1] << endl;
        }
        else if (abs(V[i][1] - (int)V[i][1]) < 0.00001) {
            cout << V[i][0] << " " << V[i][1] << ".0" << endl;
        }
        else {
            cout << V[i][0] << " " << V[i][1] << endl;
        }

    }
}

double PGArea(double V[][2], int N) {
    double num1 = 0, num2 = 0;


    for (int i = 0; i < N - 1; i++) {
        num1 += V[i][0] * V[i + 1][1];
    }
    num1 += V[N - 1][0] * V[0][1];

    for (int i = 0; i < N - 1; i++) {
      num2 += V[i][1] * V[i + 1][0];
    }
    num2 += V[N - 1][1] * V[0][0];

    double area = 0.5 * (num1 - num2);

    return area;
}
