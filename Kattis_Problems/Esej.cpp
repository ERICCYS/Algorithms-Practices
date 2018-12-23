#include<bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    unordered_set<string> essay;

    vector<char> arr;
    for (int i = 97; i < 123; i++) {
        arr.push_back(char(i));
    }
    int len;
    int id;
    string word;
    essay.clear();
    while (essay.size() < max(A, (B + 1)/ 2)) {
        len = 1 + (rand() % (15));
        word = "";
        for (int i = 0; i < len; i++) {
            id = rand() % (26);
            word.push_back(arr[id]);
        }
        essay.insert(word);
    }

    for (auto itr = essay.begin(); itr != essay.end(); itr++)  {
        cout << (*itr) << " "; 
    }

    return 0;   
}