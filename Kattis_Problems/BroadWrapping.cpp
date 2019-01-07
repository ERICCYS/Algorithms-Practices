#include<bits/stdc++.h>
using namespace std;

#define EPS 0.00000001
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define PI 3.1415926
struct P {
    double x;
    double y;
};

struct Rec{
    double x;
    double y;
    double w;
    double h;
    double v;
};

void getPoint (Rec R, P Ps[]) {
    P Um;
    P Lm;
    double ang = R.v / 180.0 * PI;
    Um.x = R.x + (R.h/2) * sin(ang);
    Um.y = R.y + (R.h/2) * cos(ang);

    Lm.x = R.x - (R.h/2) * sin(ang);
    Lm.y = R.y - (R.h/2) * cos(ang);

    Ps[0].x = Um.x - (R.w/2) * cos(ang);
    Ps[0].y = Um.y + (R.w/2) * sin(ang);

    Ps[1].x = Um.x + (R.w/2) * cos(ang);
    Ps[1].y = Um.y - (R.w/2) * sin(ang);

    Ps[2].x = Lm.x - (R.w/2) * cos(ang);
    Ps[2].y = Lm.y + (R.w/2) * sin(ang);

    Ps[3].x = Lm.x + (R.w/2) * cos(ang);
    Ps[3].y = Lm.y - (R.w/2) * sin(ang);

}
double triArea (P A, P B, P C) {
    return (A.x * B.y + C.x * A.y + B.x * C.y - C.x * B.y - B.x * A.y - A.x * C.y);
}

bool inTri (P A, P B, P C, P D) {
    double area = triArea(A, B, C);
    double sum = triArea(A, B, D) + triArea(A, C, D) + triArea(B, C, D);

    if (abs(area - sum) < EPS) {
        return 1;
    }
    else {
        return 0;
    }
}

void convPoints (P Pts[], P A, P B, P Cov[]) {

}


int main() {
    int N;
    cin >> N;

    FOR(i, 0, N - 1) {
        int M;
        cin >> M;
        Rec Recs[M];
        P Pts[4 * M];
        FOR(j, 0, M - 1) {
            cin >> Recs[j].x >> Recs[j].y >> Recs[j].w >> Recs[j].h >> Recs[j].v;
            P TPts[4];
            getPoint(Recs[j], TPts);
            FOR (i, 0, 3) {
                Pts[j * 4 + i].x = TPts[i].x;
                Pts[j * 4 + i].y = TPts[i].y;
            }
        }

        FOR (i, 0 , (4*M - 1)) {
            cout << Pts[i].x << ", " << Pts[i].y << endl;
        }
    }
}
