#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string name;
        string study;
        string borny;
        int courses;
        cin >> name >> study >> borny >> courses;
        study = study.substr(0,4);
        borny = borny.substr(0,4);
        // cout << study << " " << borny << "\n";
        stringstream ss1(study);
        int study_year;
        ss1 >> study_year;
        stringstream ss2(borny);
        int born_year;
        ss2 >> born_year;

        int e;
        // cout << study_year << " " << born_year << "\n";
        if (study_year >= 2010 || born_year >= 1991) {
            e = 1;
        } else if (courses > 40) {
            e = 0;
        } else {
            e = 2;
        }
        cout << name << " " << (e == 0 ? "ineligible" : e == 1 ? "eligible" : "coach petitions") << endl;
    }
}