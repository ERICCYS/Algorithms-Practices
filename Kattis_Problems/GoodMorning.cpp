#include<bits/stdc++.h>
using namespace std;

bool valid[201];
vector<pair<int, int>> pos(10);

bool isValid(int a, int b) {
    return ((pos[a].first <= pos[b].first) && (pos[a].second <= pos[b].second));
}

int nearest_valid(int num) {
    int a = num + 1, b = num - 1;
    while (a <= 200 && b > 0) {
        if (valid[a]) {return a;}
        if (valid[b]) {return b;}
        a++; b--;
    }
}

int main() {
    pos[0] = make_pair(4, 2);
    pos[1] = make_pair(1, 1); pos[2] = make_pair(1, 2); pos[3] = make_pair(1, 3);
    pos[4] = make_pair(2, 1); pos[5] = make_pair(2, 2); pos[6] = make_pair(2, 3);
    pos[7] = make_pair(3, 1); pos[8] = make_pair(3, 2); pos[9] = make_pair(3, 3);

    int N, num;
    bool can_reach;
    vector<int> digits;

    scanf("%d", &N);
    memset(valid, 0, sizeof(valid));

    for(int i = 0; i < 10; i++) { valid[i] = 1; }

    for(int i = 10; i <= 200; i++) {
        num = i; digits.clear();
        while (num > 0) { digits.push_back(num % 10); num /= 10; }
        can_reach = true;
        for (int j = digits.size()-1; j > 0; j--) { can_reach = can_reach && isValid(digits[j], digits[j-1]); }
        if (can_reach) { valid[i] = 1; }
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (valid[num]) { printf("%d\n", num); }
        else { printf("%d\n", nearest_valid(num)); }
    }
    
    return 0;
}