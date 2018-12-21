#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= b; (i)--)

string OtoB(string o) {
    vector<char> Bc;
    FOR(i, 0, o.size() - 1) {
        if (o[i] == '0') {
            Bc.push_back('0');
            Bc.push_back('0');
            Bc.push_back('0');
        }
        if (o[i] == '1') {
            Bc.push_back('0');
            Bc.push_back('0');
            Bc.push_back('1');
        }
        if (o[i] == '2') {
            Bc.push_back('0');
            Bc.push_back('1');
            Bc.push_back('0');
        }
        if (o[i] == '3') {
            Bc.push_back('0');
            Bc.push_back('1');
            Bc.push_back('1');
        }
        if (o[i] == '4') {
            Bc.push_back('1');
            Bc.push_back('0');
            Bc.push_back('0');
        }
        if (o[i] == '5') {
            Bc.push_back('1');
            Bc.push_back('0');
            Bc.push_back('1');
        }
        if (o[i] == '6') {
            Bc.push_back('1');
            Bc.push_back('1');
            Bc.push_back('0');
        }
        if (o[i] == '7') {
            Bc.push_back('1');
            Bc.push_back('1');
            Bc.push_back('1');
        }
    }

    string b(Bc.begin(), Bc.end());
    return b;
}


string BtoH(string b) {
    vector <char> Hc;
    int i = b.size() - 1;
    for(i = b.size() - 1; i >= 3; i -= 4) {
        if (b[i - 3] == '0') {
            if (b[i - 2] == '0') {
                if (b[i - 1] == '0') {
                    if (b[i] == '0') {
                        Hc.push_back('0');
                    }
                    else {
                        Hc.push_back('1');
                    }
                }
                else {
                    if (b[i] == '0') {
                        Hc.push_back('2');
                    }
                    else {
                        Hc.push_back('3');
                    }
                }
            }
            else {
                if (b[i - 1] == '0') {
                    if (b[i] == '0') {
                        Hc.push_back('4');
                    }
                    else {
                        Hc.push_back('5');
                    }
                }
                else {
                    if (b[i] == '0') {
                        Hc.push_back('6');
                    }
                    else {
                        Hc.push_back('7');
                    }
                }

            }
        }
        else {
            if (b[i - 2] == '0') {
                if (b[i - 1] == '0') {
                    if (b[i] == '0') {
                        Hc.push_back('8');
                    }
                    else {
                        Hc.push_back('9');
                    }
                }
                else {
                    if (b[i] == '0') {
                        Hc.push_back('A');
                    }
                    else {
                        Hc.push_back('B');
                    }
                }
            }
            else {
                if (b[i - 1] == '0') {
                    if (b[i] == '0') {
                        Hc.push_back('C');
                    }
                    else {
                        Hc.push_back('D');
                    }
                }
                else {
                    if (b[i] == '0') {
                        Hc.push_back('E');
                    }
                    else {
                        Hc.push_back('F');
                    }
                }

            }
        }

    }
    if (i == 2) {
        if (b[i - 2] == '0') {
            if (b[i - 1] == '0') {
                if (b[i] == '0') {
                    Hc.push_back('0');
                }
                else {
                    Hc.push_back('1');
                }
            }
            else {
                if (b[i] == '0') {
                    Hc.push_back('2');
                }
                else {
                    Hc.push_back('3');
                }
            }
        }
        else {
            if (b[i - 1] == '0') {
                if (b[i] == '0') {
                    Hc.push_back('4');
                }
                else {
                    Hc.push_back('5');
                }
            }
            else {
                if (b[i] == '0') {
                    Hc.push_back('6');
                }
                else {
                    Hc.push_back('7');
                }
            }

        }
    }
    if (i == 1) {
        if (b[i - 1] == '0') {
            if (b[i] == '0') {
                Hc.push_back('0');
            }
            else {
                Hc.push_back('1');
            }
        }
        else {
            if (b[i] == '0') {
                Hc.push_back('2');
            }
            else {
                Hc.push_back('3');
            }
        }
    }
    if (i == 0) {
        Hc.push_back(b[i]);
    }

    string h(Hc.rbegin(), Hc.rend());
    return h;
}
int main() {
    string o;
    cin >> o;
    string b;
    b = OtoB(o);
    // cout << b << endl;
    string h;
    
    h = BtoH(b);
    while (h.size() > 1 && h[0] == '0') {
        // cout << "h[0] == 0" << endl;
        h = h.substr(1);
    }
    cout << h;
}
