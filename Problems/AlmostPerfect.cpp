#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)


int main() {
    int N;
    string S;
    getline(cin,S);
    while (S.length() != 0) {
        stringstream geek(S);
        geek >> N;
        set <int> Div;
        set <int> :: iterator itr;
        int n = (int)sqrt(N) + 1;
        FOR (i, 2, n) {
            if (N % i == 0){
                Div.insert(i);
            }
        }
        for (itr = Div.begin(); itr != Div.end(); ++itr)
        {
            Div.insert(N / (*itr));
        }
        int sum = 0;
        for (itr = Div.begin(); itr != Div.end(); ++itr)
        {
            sum += *itr;
        }
        Div.insert(1);
        sum++;

        if (sum == N) {
            cout << N << " " << "perfect" << endl;
        }
        else if (abs(sum - N) <= 2) {
            cout << N << " " << "almost perfect" << endl;
        }
        else{
            cout << N << " not perfect" << endl;
        }
        getline(cin,S);
    }
}
