#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= b; (i)--)


int main() {
    int H;
    cin >> H;
    string cmd = "\0";
    getline(cin, cmd);
    if (cmd != "\0")
        cmd = cmd.substr(1);

    int base = pow(2, (H + 1)) - 1;
    int result = base;

    int preSub;
    char preDir;
    if (cmd[0] == 'L') {
        preSub = 1;
        preDir = 'L';
        result -= 1;
    }
    else if (cmd[0] == 'R') {
        preSub = 2;
        preDir = 'R';
        result -= 2;
    }
    else {
        cout << base << endl;
        return 0;
    }
    cmd = cmd.substr(1);
    while (cmd != "\0") {
        if (cmd[0] == preDir) {
            result -= preSub * 2;
            preSub *= 2;
        }
        else {
            if (cmd[0] == 'R' && preDir == 'L') {
                result -= (preSub * 2 + 1);
                preSub = (preSub * 2 + 1);
                preDir = 'R';
            }
            else if (cmd[0] == 'L' && preDir == 'R') {
                result -= (preSub * 2 - 1);
                preSub = (preSub * 2 - 1);
                preDir = 'L';
            }
        }
        cmd = cmd.substr(1);
    }
    cout << result << endl;
    // cout << H << " " << cmd << endl;
}