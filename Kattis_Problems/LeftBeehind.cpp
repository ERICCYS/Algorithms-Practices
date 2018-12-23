#include<bits/stdc++.h>
using namespace std;
int main() {
    int sw, so;
    while (scanf("%d %d", &sw, &so), (sw || so)) {
        if(sw + so == 13) {
            cout << "Never speak again.\n";
        }
        else if (sw > so) {
            cout << "To the convention.\n";
        }
        else if (sw < so) {
            cout << "Left beehind.\n";
        } else {
            cout << "Undecided.\n";
        }
    }
}