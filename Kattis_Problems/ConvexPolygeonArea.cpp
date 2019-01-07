#include<bits/stdc++.h>
using namespace std;

double area(int[], int[], int[]);

int main() {
    int N;
    cin >> N;

    double As[N] = {0.0};
    int index = 0;
    for (int i = 0; i < N; i++) {
        int E;
        cin >> E;
        int V[E][2] = {{0,0}};
        for (int j = 0; j < E; j++) {
            cin >> V[j][0] >> V[j][1];
        }

        double A = 0;
        for (int j = 1; j < E - 1; j++) {
            A += area(V[0], V[j], V[j + 1]);
        }


        As[index] = A;
        index++;
    }

    for (int j = 0; j < N; j++) {
        cout << As[j] << endl;
    }
    return 0;
}

double area(int p1[], int p2[], int p3[]) {
//    cout << "This part of area is enclosed by" << p1[0] << " " << p1[1] << "   " << p2[0] << " " << p2[1] << "   " << p3[0] << " " << p3[1] << endl;
    double area = 0.5 * abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1]));
//    cout << "This part has an area of " << area << endl;
    return area;
}
