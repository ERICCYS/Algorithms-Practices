#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)

int score(char a, char b) {
    // cout << a << " " << b << endl;
    int m;
    if ((a == '1' && b == '2') || (a == '2' && b == '1'))  
        m = 1000;

    else if (a == b) {
        if (a == '1')
            m = 111;
        if (a == '2')
            m = 222;
        if (a == '3')
            m = 333;
        if (a == '4')
            m = 444;
        if (a == '5')
            m = 555;
        if (a == '6')
            m = 666;
    }

    else {
        if (a > b) 
            m = int(a - 48) * 10  + int(b - 48);
        else 
            m = int(b - 48) * 10  + int(a - 48);
    }
    return m;
}


void reduce(int a, int b) {
    if (a == 0) {
        cout << 0 << endl;
        return ;
    }
    if (a == b) {
        cout << 1 << endl;
        return ;
    }
    int d = __gcd(a, b);
    cout << a/d << "/" << b/d << endl;
}

int main() {
    char s0, s1, r0, r1;

    while(cin >> s0 >> s1 >> r0 >> r1) {
        if (s0 == '0')
            return 0;
        
        int ms = 0, mr = 0;

        if (s0 != '*' && s1 != '*' && r0 != '*' && r1 != '*') {
            ms = score(s0, s1);
            mr = score(r0, r1);
            if (ms > mr)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        
        else if (s0 == '*' && s1 != '*' && r0 != '*' && r1 != '*') {
            int tc = 6;
            int wc = 0;
            mr = score(r0, r1);
            for (int i = 49; i <= 54; i++) {
                ms = score(char(i), s1);
                if (ms > mr)
                    wc++;
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 == '*' && r0 != '*' && r1 != '*') {
            int tc = 6;
            int wc = 0;
            mr = score(r0, r1);
            for (int i = 49; i <= 54; i++) {
                ms = score(s0, char(i));
                if (ms > mr)
                    wc++;
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 != '*' && r0 == '*' && r1 != '*') {
            int tc = 6;
            int wc = 0;
            ms = score(s0, s1);
            for (int i = 49; i <= 54; i++) {
                mr = score(char(i), r1);
                if (ms > mr)
                    wc++;
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 != '*' && r0 != '*' && r1 == '*') {
            int tc = 6;
            int wc = 0;
            ms = score(s0, s1);
            for (int i = 49; i <= 54; i++) {
                mr = score(r0, char(i));
                if (ms > mr)
                    wc++;
            }
            reduce(wc, tc);
        }

        else if (s0 == '*' && s1 == '*' && r0 != '*' && r1 != '*') {
            int tc = 36;
            int wc = 0;
            mr = score(r0, r1);
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    ms = score(char(i), char(j));
                    if (ms > mr)
                        wc++;
                }
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 != '*' && r0 == '*' && r1 == '*') {
            int tc = 36;
            int wc = 0;
            ms = score(s0, s1);
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    mr = score(char(i), char(j));
                    if (ms > mr)
                        wc++;
                }
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 == '*' && r0 != '*' && r1 == '*') {
            int tc = 36;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    ms = score(s0, char(i));
                    mr = score(r0, char(j));
                    if (ms > mr)
                        wc++;
                }
            }
            reduce(wc, tc);
        }

        else if (s0 == '*' && s1 != '*' && r0 == '*' && r1 != '*') {
            int tc = 36;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    ms = score(char(i), s1);
                    mr = score(char(j), r1);
                    if (ms > mr) 
                        wc++;
                }
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 == '*' && r0 == '*' && r1 != '*') {
            int tc = 36;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    ms = score(s0, char(i));
                    mr = score(char(j), r1);
                    if (ms > mr)
                        wc++;
                }
            }
            reduce(wc, tc);
        }
        
        else if (s0 == '*' && s1 != '*' && r0 != '*' && r1 == '*') {
            int tc = 36;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    ms = score(char(i), s1);
                    mr = score(r0, char(j));
                    if (ms > mr)
                        wc++;
                }
            }
            reduce(wc, tc);
        }


        else if (s0 == '*' && s1 == '*' && r0 == '*' && r1 != '*') {
            int tc = 216;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    for(int k = 49; k <= 54; k++) {
                        ms = score(char(i), char(j));
                        mr = score(char(k), r1);
                        if (ms > mr)
                            wc++;   
                    }
                    
                }
            }
            reduce(wc, tc);
        }

        else if (s0 == '*' && s1 == '*' && r0 != '*' && r1 == '*') {
            int tc = 216;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    for(int k = 49; k <= 54; k++) {
                        ms = score(char(i), char(j));
                        mr = score(r0, char(k));
                        if (ms > mr)
                            wc++;   
                    }
                    
                }
            }
            reduce(wc, tc);
        }

        else if (s0 == '*' && s1 != '*' && r0 == '*' && r1 == '*') {
            int tc = 216;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    for(int k = 49; k <= 54; k++) {
                        ms = score(char(i), s1);
                        mr = score(char(j), char(k));
                        if (ms > mr)
                            wc++;   
                    }
                    
                }
            }
            reduce(wc, tc);
        }

        else if (s0 != '*' && s1 == '*' && r0 == '*' && r1 == '*' ) {
            int tc = 216;
            int wc = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    for(int k = 49; k <= 54; k++) {
                        ms = score(s0, char(i));
                        mr = score(char(j), char(k));
                        if (ms > mr)
                            wc++;   
                    }
                    
                }
            }
            reduce(wc, tc);
        }

        else if (s0 == '*' && s1 == '*' && r0 == '*' && r1 == '*') {
            int tc = 1296;
            int wc = 0;
            int ec = 0;
            for (int i = 49; i <= 54; i++) {
                for (int j = 49; j <= 54; j++) {
                    for(int k = 49; k <= 54; k++) {
                        for (int l = 49; l <= 54; l++) {
                            ms = score(char(i), char(j));
                            mr = score(char(k), char(l));
                            if (ms > mr)
                                wc++;
                            else if (ms == mr)
                                ec++;
                        }
                    }
                }
            }
            // cout << ec << endl;
            reduce(wc, tc);
        }
    }
}