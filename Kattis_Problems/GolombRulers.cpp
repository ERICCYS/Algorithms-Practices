#include<bits/stdc++.h>
using namespace std;

int arr[2001];

int maximum(vector<int> nums) {
    int n = nums[0];
    for (int i = 0; i < nums.size(); i++) {if (nums[i] >= n) {n = nums[i];}}
    return n;
}

int main(){
    string numstr;
    vector<int> nums;
    vector<int> missing;
    int n;
    while(getline(cin, numstr)) {
        memset(arr, 0, sizeof(arr));
        istringstream is(numstr);
        nums.clear();
        missing.clear();
        while (is >> n) {nums.push_back(n);}
        for(int i = 0; i < nums.size()-1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {arr[abs(nums[i] - nums[j])]++;}
        }
        int isRuler = true;
        for(int i = 1; i <= maximum(nums); i++) {
            if (arr[i] >= 2) {isRuler = false; break;}
            if (arr[i] == 0) {missing.push_back(i);}
        }
        if (!isRuler) {printf("not a ruler\n");}
        else {
            if (missing.size()==0) {printf("perfect\n");}
            else {
                printf("missing");
                for (int x : missing) {printf(" %d", x);}
                printf("\n");
            }
        }
    }
    return 0;
}