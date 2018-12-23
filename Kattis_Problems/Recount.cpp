#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> votes;
    string name;
    while(getline(cin, name)) {
        if (name == "***") {
            break;
        } else {
            if (votes.find(name) == votes.end()) {
                votes[name] = 1;
            } else {
                votes[name] += 1;
            }
        }
    }

    int max_votes = 0;
    for (auto itr = votes.begin(); itr != votes.end(); itr++) { 
        max_votes = max(max_votes, itr->second);
    }

    vector<string> names;
    for (auto itr = votes.begin(); itr != votes.end(); itr++) { 
        if (itr->second == max_votes) {
            names.push_back(itr->first);
        }
    }

    if (names.size() > 1) {
        cout << "Runoff!";
    } else {
        cout << names[0];
    }
}