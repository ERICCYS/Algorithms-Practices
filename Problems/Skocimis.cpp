#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(B - A, C - B) - 1;
    return 0;
}
