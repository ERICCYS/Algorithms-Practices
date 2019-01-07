#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int C = 1;
    char S[9] = {'\0'};
    cin.getline(S,9);
    string str(S);
    while (str.length() >= 2) {
        if (str.length() == 7) {
            cout << "Case " << C << ": " << "UNIQUE" << endl;
        }
        else if (str[1] == 'b') {
            str[1] = '#';
            if (str[0] != 'A')
                str[0] = (char)((int)str[0] - 1);
            else
                str[0] = 'G';getchar();
            cout << "Case " << C << ": " << str << endl;
        }
        else if (str[1] == '#') {
            str[1] = 'b';
            if (str[0] != 'G')
                str[0] = (char)((int)str[0] + 1);
            else
                str[0] = 'A';
            cout << "Case " << C << ": " << str << endl;
        }
        C++;
        cin.getline(S,9);
        str = S;
    }
    return 0;
}
