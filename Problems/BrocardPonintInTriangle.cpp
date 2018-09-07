#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.141592653
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define sqr(x) ((x) * (x))
#define INF 1000000000000

struct P{
    double x;
    double y;
};

struct L{
    P Pt;
    double K;
};

double OmegaAngle(P A, P B, P C) {
    double a = sqrt(sqr(C.x - B.x) + sqr(C.y - B.y));
    double b = sqrt(sqr(C.x - A.x) + sqr(C.y - A.y));
    double c = sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
    double angA, angB, angC;
    angA = acos((sqr(b)  + sqr(c) - sqr(a)) / (2 * b * c));
    angB = acos((sqr(a)  + sqr(c) - sqr(b)) / (2 * a * c));
    angC = acos((sqr(a)  + sqr(b) - sqr(c)) / (2 * a * b));
    double cotA, cotB, cotC;

    cotA = 1 / tan(angA);
    cotB = 1 / tan(angB);
    cotC = 1 / tan(angC);

    double cotO = cotA + cotB + cotC;
    double O = atan(1 / cotO);
    return O;
}

L PositiveOmegaShift(L l, double O) {
//    cout << "Before shift K = " << l.K << endl;
    double ang = atan(l.K);
    if(ang < 0) {
        ang += PI;
    }
//    cout << "Angle is : " << (ang * 180 / PI) << endl;
    double newAng = ang + O;
    if (newAng > PI) {
        newAng -= PI;
    }
//    cout << "After shift angle is: " << (newAng * 180 / PI) << endl;
    L newL;
    newL.K = tan(newAng);
//    cout << "After shift K = " << newL.K << endl;
    newL.Pt = l.Pt;
    return newL;
}

L NegativeOmegaShift(L l, double O) {
//    cout << "Before shift K = " << l.K << endl;
    double ang = atan(l.K);
    if(ang < 0) {
        ang += PI;
    }
//    cout << "Angle is : " << (ang * 180 / PI) << endl;
    double newAng = ang - O;
    if (newAng < 0) {
        newAng += PI;
    }
//    cout << "After shift angle is: " << (newAng * 180 / PI) << endl;
    L newL;
    newL.K = tan(newAng);
//    cout << "After shift K = " << newL.K << endl;
    newL.Pt = l.Pt;
    return newL;
}

int PointIn (P A, P B, P C, P interP) {
//    cout << p1[0] << p1[1] << p2 [0] << p2[1] << p3[0] << p3[1];
    double area = 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    double area1 = 0.5 * abs(interP.x * (B.y - C.y) + B.x * (C.y - interP.y) + C.x * (interP.y - B.y));
    double area2 = 0.5 * abs(A.x * (interP.y - C.y) + interP.x * (C.y - A.y) + C.x * (A.y - interP.y));
    double area3 = 0.5 * abs(A.x * (B.y - interP.y) + B.x * (interP.y - A.y) + interP.x * (A.y - B.y));
//    cout << area << endl;
//    cout << (area1 + area2 + area3) << endl;
    if (abs(area - (area1 + area2 + area3)) < 0.0001) {
        return 1;
    }
    else {
        return 0;
    }
}


P Intersect(L l1, L l2) {
    P interP;
//    cout << l1.K << " "  << l2.K << endl;
    interP.x = ((l2.Pt.y - l1.Pt.y) + (l1.K * l1.Pt.x - l2.K * l2.Pt.x)) / (l1.K - l2.K);
    interP.y = ((l2.Pt.y * l1.K - l1.Pt.y * l2.K) - ((l1.K * l2.K) * (l2.Pt.x - l1.Pt.x))) / (l1.K - l2.K);

    return interP;
}

int main() {
    int C;
    cin >> C;

    int buffer;
    FOR(i, 1, C) {
        P A, B, C;
        cin >> buffer >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        double O = OmegaAngle(A, B, C);
//        cout << (O * 180 / PI) << endl;
        L AB, BC;
        AB.Pt = A;
        BC.Pt = B;
        AB.K = (abs(A.x - B.x) < 0.000001) ? INF : ((B.y - A.y) / (B.x - A.x));
        BC.K = (abs(C.x - B.x) < 0.000001) ? INF : ((C.y - B.y) / (C.x - B.x));
//        cout << AB.K << " " << BC.K << endl;
        L AP, BP;

        AP = PositiveOmegaShift(AB, O);
        BP = PositiveOmegaShift(BC, O);

        P interP = Intersect(AP, BP);
        if (PointIn(A, B, C, interP) == 1) {
//            cout << "+, +" << endl;
            cout << i << " " << interP.x << " " << interP.y << endl;
            continue;
        }
    }
}
