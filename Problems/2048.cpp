#include <iostream>

using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)
int main() {
    int A[4][4] = {{0,0}};

    FOR(i, 0, 3) {
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];
    }

    int c;
    cin >> c;

    bool B[4][4] = {{0,0}};
    if (c == 0) {
        FOR(i, 0, 3) {
            FOR (j, 1, 3) {
                if (A[i][j] == 0)
                    continue;

                else if (A[i][j - 1] == 0) {
                    int t = j - 1;
                    while (A[i][t] == 0 && t >= 0) {
                        A[i][t] = A[i][t + 1];
                        A[i][t + 1] = 0;
                        t--;
                    }
                    if (A[i][t] == A[i][t + 1] && B[i][t] == 0) {
                        A[i][t] = 2 * A[i][t];
                        A[i][t + 1] = 0;
                        B[i][t] = 1;
                    }
                }

                else if (A[i][j - 1] == A[i][j] && B[i][j - 1] == 0) {
                    A[i][j - 1] *= 2;
                    A[i][j] = 0;
                    B[i][j - 1] = 1;
                }
            }
        }

        FOR(i, 0, 3) {
            FOR (j, 0, 3) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (c == 1) {
        FOR(j, 0, 3) {
            FOR (i, 1, 3) {
                if (A[i][j] == 0)
                    continue;

                else if (A[i - 1][j] == 0) {
                    int t = i - 1;
                    while (A[t][j] == 0 && t >= 0) {
                        A[t][j] = A[t + 1][j];
                        A[t + 1][j] = 0;
                        t--;
                    }
                    if (A[t][j] == A[t + 1][j] && B[t][j] == 0) {
                        A[t][j] = 2 * A[t][j];
                        A[t + 1][j] = 0;
                        B[t][j] = 1;
                    }
                }

                else if (A[i - 1][j] == A[i][j] && B[i - 1][j] == 0) {
                    A[i - 1][j]  *= 2;
                    A[i][j] = 0;
                    B[i - 1][j] = 1;
                }
            }
        }

        FOR(i, 0, 3) {
            FOR (j, 0, 3) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (c == 2) {
        FOR(i, 0, 3) {
            ROF(j, 2, 0) {
                if (A[i][j] == 0)
                    continue;

                else if (A[i][j + 1] == 0) {
                    int t = j + 1;
                    while (A[i][t] == 0 && t <= 3) {
                        A[i][t] = A[i][t - 1];
                        A[i][t - 1] = 0;
                        t++;
                    }
                    if (A[i][t] == A[i][t - 1] && B[i][t] == 0) {
                        A[i][t] *= 2;
                        A[i][t - 1] = 0;
                        B[i][t] = 1;
                    }
                }

                else if (A[i][j + 1] == A[i][j] && B[i][j + 1] == 0) {
                    A[i][j + 1] *= 2;
                    A[i][j] = 0;
                    B[i][j + 1] = 1;
                }
            }
        }

        FOR(i, 0, 3) {
            FOR (j, 0, 3) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

    }
    else if (c == 3) {
        FOR(j, 0, 3) {
            ROF (i, 2, 0) {
                if (A[i][j] == 0)
                    continue;

                else if (A[i + 1][j] == 0) {
                    int t = i + 1;
                    while (A[t][j] == 0 && t <= 3) {
                        A[t][j] = A[t - 1][j];
                        A[t - 1][j] = 0;
                        t++;
                    }
                    if (A[t][j] == A[t - 1][j] && B[t][j] == 0) {
                        A[t][j] = 2 * A[t][j];
                        A[t - 1][j] = 0;
                        B[t][j] = 1;
                    }
                }

                else if (A[i + 1][j] == A[i][j] && B[i + 1][j] == 0) {
                    A[i + 1][j]  *= 2;
                    A[i][j] = 0;
                    B[i + 1][j] = 1;
                }
            }
        }

        FOR(i, 0, 3) {
            FOR (j, 0, 3) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}
