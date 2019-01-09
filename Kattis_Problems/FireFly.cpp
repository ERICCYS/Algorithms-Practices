#include<bits/stdc++.h>
using namespace std;

int obstacles[500002]; 

int main() {
    int N, H, len;
    scanf("%d %d", &N, &H);
    
    for (int i = 0; i < N/2; i++) {
        scanf("%d", &len);
        obstacles[1]++; obstacles[len+1]--;
        scanf("%d", &len);
        obstacles[H-len+1]++; obstacles[H+1]--;
    }
    for (int i = 2; i <= H; i++) { obstacles[i] += obstacles[i-1]; }
    
    int min_obs = obstacles[1];
    for (int i = 1; i <= H; i++) { min_obs = min(obstacles[i], min_obs); }

    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        if (obstacles[i] == min_obs) { cnt++; }
    }

    cout << min_obs << " " << cnt << endl;
    return 0;
}