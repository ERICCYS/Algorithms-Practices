#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define PI 3.141592653589793

int main() {
    int M, N;
    double R;
    cin >> M >> N;
    cin >> R;

    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    cout.precision(10);
    double dis1, dis2;
    if (Ax != Bx) {
        dis1 = (abs(Ax - Bx) / double(M) * PI) * (((min(Ay, By)) * R) / N) + ((R / N) * (abs(Ay - By)));
        dis2 = (Ay + By) / double(N) * R; 
        cout << min(dis1, dis2);
    } else {
        cout << (abs(Ay - By) / double(N) * R); 
    }
    
}