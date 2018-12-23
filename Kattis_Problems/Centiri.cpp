#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num[3];
    cin >> num[0] >> num[1] >> num[2];

    sort(num, num + 3);

    int dif_A = num[1] - num[0];
    int dif_B = num[2] - num[1];

    if (dif_A == dif_B) {
        cout << num[2] + dif_A;
    }
    else if (dif_A == 2 * dif_B) {
        cout << num[0] + dif_B;
    }
    else if (dif_B == 2 * dif_A) {
        cout << num[1] + dif_A;
    }

}
