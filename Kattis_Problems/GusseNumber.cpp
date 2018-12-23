#include <iostream>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int left = 1;
    int right = 1000;
    int guess = left + (right - left) / 2;

    string s;
    while (1){
        cout << guess << endl;
        cout << flush;
        cin >> s;
        if (s == "higher") {
            left = guess + 1;
            guess = left + (right - left) / 2;
            continue;
        }
        else if (s == "lower"){
            right = guess - 1;
            guess = left + (right - left) / 2;
            continue;
        }
        else {

            break;
        }
    }
}
