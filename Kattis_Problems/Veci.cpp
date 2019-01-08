#include<bits/stdc++.h>
using namespace std;

vector<int> results;

int main() {
    vector<int> digits;
    int x, temp;
    scanf("%d", &x);
    temp = x;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    if (digits.size() == 0) { printf("0\n"); return 0; }
    
    sort(digits.begin(), digits.end());
    int num;
    do {
        num = 0;
        for(auto n : digits) { num *= 10; num += n; }
        results.push_back(num);
    } while (next_permutation(digits.begin(),digits.end()));

    for (int i = 0;  i < results.size(); i++) {
        if (x == results[i]) {
            if (i == results.size()-1) { printf("0\n"); return 0; }
            else { printf("%d\n", results[i + 1]); return 0;}
        }
    }
    return 0;
}