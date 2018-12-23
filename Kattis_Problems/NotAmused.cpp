#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    string name;
    int d = 1;
    int t;
    map<string, int> logs;
    while(cin >> str) {
        if (str == "OPEN") {
            logs.clear();
            while(cin >> str) {
                if (str == "CLOSE") {
                    cout << "Day " << d << endl;
                    for (auto itr = logs.begin(); itr != logs.end(); itr++) {
                        cout << itr->first;
                        printf(" $%.2f\n", 0.1 * itr->second);
                    }
                    cout << endl;
                    d++;
                    break;
                } else if (str == "ENTER") {
                    cin >> name;
                    cin >> t;
                    if (logs.find(name) != logs.end()) {
                        logs[name] = t - logs[name];
                    } else {
                        logs[name] = t;
                    }
                    
                } else if (str == "EXIT") {
                    cin >> name;
                    cin >> t;
                    logs[name] = t - logs[name];
                }
            }
        }
    }
}