#include<bits/stdc++.h>
using namespace std;

int main() {
    int w, l;
    char dr;
    int di;
    int r_x = 0, r_y = 0, t_x = 0, t_y = 0;
    while (scanf("%d" "%d", &w, &l) && (w || l)) {
        // cout << w << " " << l << endl;
        int s;
        cin >> s;
        // cout << s << endl;
        r_x = 0, r_y = 0, t_x = 0, t_y = 0;
        while(s--) {
            getchar();
            cin >> dr >> di;
            // cout << dr << " " << di << endl;
            if (dr == 'u') {
                r_y = min(l-1, r_y + di);
                t_y += di;
            }
            if (dr == 'd') {
                r_y = max(0, r_y - di);
                t_y -= di;
            }
            if (dr == 'r') {
                r_x = min(w-1, r_x + di);
                t_x += di;
            }
            if (dr == 'l') {
                r_x = max(0, r_x - di);
                t_x -= di;
            }
        }
        cout << "Robot thinks " << t_x << " " << t_y << endl;
        cout << "Actually at " << r_x << " " << r_y << endl;
        cout << "\n";
    }
}