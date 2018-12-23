#include<bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)

map <string, int> db;
map <string, int>::iterator it;

void defineNew(string defword, int value) {
    it = db.find(defword);
    if (it != db.end())
        db.erase(it);

    db.insert(psi (defword, value));
}



void printResult(string words[], char ops[], bool unknown, int result = 0) {
    int i = 0;
    if (unknown) {
        while (ops[i] != '\0') {
            cout << words[i] << " " << ops[i] << " ";
            i++;
        }
        cout << "unknown" << endl;
    }
    else {
        while (ops[i] != '\0') {
            cout << words[i] << " " << ops[i] << " ";
            i++;
        }
        string r;
        for (it = db.begin(); it != db.end(); ++it) {
            if (it->second == result) {
                cout << it->first << endl;
                return ;
            }
        }
        cout << "unknown" << endl;
    }
}

void calculate(string words[], char ops[]) {
    int i = 0;
    int r = 0;
    int values[16] = {0};

    while(ops[i] != '\0') {
        it = db.find(words[i]);
        if (it == db.end()) {
            printResult(words, ops, true);
            return ;
        }
        else {
            if (i == 0)
                r += it->second;
            else {
                if (ops[i - 1] == '+')
                    r += it->second;
                else
                    r -= it->second;
            }
        }
        i++;
    }
    printResult(words, ops, false, r);
}
int main() {
    // db.insert(psi ("hello", 0));
    // db.insert(psi ("world", 2));
    // db.insert(psi ("Iam", 3));
    // db.insert(psi ("Eric", 4));
    // cout << db.find("world")->second;
    string cmd;
    string defword;
    string words[16];
    char ops[16] = {'\0'};
    int value;
    while (cin >> cmd) {
        if (cmd == "def") {
            cin >> defword;
            cin >> value;
            defineNew(defword, value);
        }
            
        else if (cmd == "calc") {
            FOR(i, 0, 15) {
                ops[i] = '\0';
            }
            FOR(i, 0, 15) {
                words[i] = "\0";
            }
            int i = -1;

            do {
                i++;
                cin >> words[i];
                cin >> ops[i];
            } while (ops[i] == '+' || ops[i] == '-');
            calculate(words, ops);
        }

        else
            db.clear();
    }
}