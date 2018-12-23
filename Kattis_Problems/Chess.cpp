#include<bits/stdc++.h>
using namespace std;

int toX(char x) {
    return int(x) - 65;
}

int toY(char y) {
    return int(y) - 49;
}

char tox(int x) {
    return char(x + 65);
}

char toy(int y) {
    return char(y + 49);
}

int main() {
    int T;
    cin >> T;
    getchar;
    char s_x, s_y, e_x, e_y; 
    while (T--) {
        cin >> s_x;
        getchar();
        cin >> s_y;
        getchar();
        cin >> e_x;
        getchar();
        cin >> e_y;
        getchar();
        // cout << s_x << " " << s_y << " " << e_x << " " << e_y << endl;
        // cout << toX(s_x) << " " << toY(s_y) << " " << toX(e_x) << " " << toY(e_y) << endl;

        int s_X = toX(s_x);
        int s_Y = toY(s_y);
        int e_X = toX(e_x);
        int e_Y = toY(e_y);

        if (s_X == e_X && s_Y == e_Y) {
            cout << 0 << " " << s_x << " " << s_y << endl;
        } else {
            if (abs(s_X - e_X) == abs(s_Y - e_Y)) {
                cout << 1 << " " << s_x << " " << s_y << " " << e_x << " " << e_y << endl;
            } else {
                bool exist = false;
                for (int i = 0; i < 8; i++) {
                    for(int j = 0; j < 8; j++) {
                        if (abs(i - s_X) == abs(j - s_Y) && abs(i - e_X) == abs(j - e_Y)) {
                            cout << 2 << " " << s_x << " " << s_y << " " << tox(i) << " " << toy(j) << " " << e_x << " " << e_y << endl;
                            exist = true;
                            break;
                        }
                    }
                    if (exist) break;
                }
                if (!exist) {
                    cout << "Impossible" << endl;
                }
            }
        }
    }
}