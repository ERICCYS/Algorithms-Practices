#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<string, vector<string>> report;
    string name;
    string item;
    while (cin >> n && n != 0) {
        report.clear();
        for (int i = 0; i < n; i++) {
            cin >> name;
            while (getchar() != '\n') {
                cin >> item;
                if (report.find(item) == report.end()) {
                    vector<string> names;
                    names.push_back(name);
                    report[item] = names;
                } else {
                    report[item].push_back(name);
                }
            }
        }
        for (auto itr = report.begin(); itr != report.end(); itr++) {
            cout << itr->first << " ";
            sort(itr->second.begin(), itr->second.end());
            for (int i = 0; i < itr->second.size(); i++) {
                cout << itr->second[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}