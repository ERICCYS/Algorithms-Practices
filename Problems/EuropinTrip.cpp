#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.1415926
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define sqr(x) ((x) * (x))
struct P{
    double x;
    double y;
};
double Angle(P A, P B, P C) {
    double a = sqrt(sqr(C.x - B.x) + sqr(C.y - B.y));
    double b = sqrt(sqr(C.x - A.x) + sqr(C.y - A.y));
    double c = sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
    double angle = 0;
    angle = acos((sqr(b)  + sqr(c) - sqr(a)) / (2 * b * c));
    angle *= (180 / PI);
    return angle;
}

double K(P A, P B) {
    double AT = atan((B.y - A.y) / (B.x - A.x));
    return AT > 0 ? AT : (AT + PI*0.5);
}
bool Side (P A, P B, P C) {
    double K = (B.y - A.y) / (B.x - A.x);
    double I = ((B.x * A.y) - (B.y * A.x)) / (B.x - A.x);

    if ((K * C.x) + I - C.y > 0)
        return 1;
    else
        return 0;
}
P findPoint(P A, P B, P C) {
    P M;
    P R;
    M.x = 0.5 * (A.x + B.x);
    M.y = 0.5 * (A.y + B.y);

    double len;
    len = sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));

    if (A.x == B.x) {
        if (C.x > A.x) {
            R.x = A.x - len * (sqrt(3) / 2);
        }
        else {
           R.x = A.x + len * (sqrt(3) / 2);
        }
        R.y = 0.5 * (A.y + B.y);
        return R;
    }
    else if (A.y == B.y){
        if (C.y > A.y) {
            R.y = A.y - len * (sqrt(3) / 2);
        }
        else {
           R.y = A.y + len * (sqrt(3) / 2);
        }
        R.x = 0.5 * (A.x + B.x);
        return R;
    }
    else {
        double K = (B.x - A.x) / (A.y - B.y);
        double ang = atan(K);
        if (ang < 0) {
            ang += PI;
        }

        P Pcan[2];

        Pcan[0].x = M.x + len * (sqrt(3) / 2) * cos(ang);
        Pcan[0].y = M.y + len * (sqrt(3) / 2) * sin(ang);

        Pcan[1].x = M.x - len * (sqrt(3) / 2) * cos(ang);
        Pcan[1].y = M.y - len * (sqrt(3) / 2) * sin(ang);

        FOR(i, 0, 1) {
            bool CSide = Side(A, B, C);
            if (Side(A, B, Pcan[i]) != CSide){
                R.x = Pcan[i].x;
                R.y = Pcan[i].y;
                break;
            }
        }
        return R;
    }
}


P findIntersec (P A1, P A2, P B1, P B2) {
    double Ka = (A1.y - A2.y) / (A1.x - A2.x);
    double Ia = ((A1.x * A2.y) - (A1.y * A2.x)) / (A1.x - A2.x);
    double Kb = (B1.y - B2.y) / (B1.x - B2.x);
    double Ib = ((B1.x * B2.y) - (B1.y * B2.x)) / (B1.x - B2.x);

    P R;
    R.x = (Ib - Ia) / (Ka - Kb);
    R.y = ((Ia * Kb) - (Ib * Ka)) / (Kb - Ka);
    return R;
}

int main() {
    P Ps[3];
    FOR(i, 0, 2) {
        cin >> Ps[i].x >> Ps[i].y;
    }

    double A = Angle(Ps[0], Ps[1], Ps[2]);
    double B = Angle(Ps[1], Ps[2], Ps[0]);
    double C = Angle(Ps[2], Ps[0], Ps[1]);

    double max = 120.0;

    if (A >= max) {
        cout << Ps[0].x << " " << Ps[0].y;
        return 0;
    }
    else if (B >= max) {
        cout << Ps[1].x << " " << Ps[1].y;
        return 0;
    }
    else if (C >= max) {
        cout << Ps[2].x << " " << Ps[2].y;
        return 0;
    }
    else{
        P B1, C1;
        C1 = findPoint(Ps[0], Ps[1], Ps[2]);
        B1 = findPoint(Ps[0], Ps[2], Ps[1]);
        P R;
        R = findIntersec(Ps[2], C1, Ps[1], B1);
        cout << R.x << " " << R.y;

    }
    return 0;
}

