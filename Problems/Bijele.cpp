#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int Tar[6] =  {1,1,2,2,2,8};
    int Inp[6] = {0};

    FOR(i,0,5) {cin >> Inp[i];}
    FOR(i,0,5) {cout << Tar[i] - Inp[i] << " ";}

    return 0;
}
