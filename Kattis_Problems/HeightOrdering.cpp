#include<bits/stdc++.h>
using namespace std;

int main() {
    int P;
    scanf("%d", &P);
    int dummy;
    int arr[20];
    int cnt;
    while(P--) {
        scanf("%d", &dummy);
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        for (int i = 0; i < 20; i++) { scanf("%d", &arr[i]); }
        for(int i = 1; i < 20; i++) {
            for(int j = i; j > 0; j--) {
                if (arr[j] < arr[j-1]) {int temp = arr[j]; arr[j] = arr[j-1]; arr[j-1] = temp; cnt++;}
                else {break;}
            }
        }
        printf("%d %d\n", dummy, cnt);
    }
    return 0;
}