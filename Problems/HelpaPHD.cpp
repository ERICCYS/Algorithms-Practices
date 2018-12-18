#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        if(s == "P=NP") {
            cout << "skipped\n";
        }
        else {
            int i = s.find("+");
            stringstream op1(s.substr(0,i));
            int o1 = 0;
            op1 >> o1;
            stringstream op2(s.substr(i+1));
            int o2 = 0;
            op2 >> o2;
            cout << (o1 + o2) << endl;
        }
    }
}