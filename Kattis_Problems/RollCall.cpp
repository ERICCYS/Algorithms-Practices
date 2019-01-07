#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)

struct Name {
  string fn;
  string ln;
  bool full;
};

template<typename Out>
void split(const string &s, char delim, Out result) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    *(result++) = item;
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

bool compare (Name A, Name B) {
  int result = (A.ln < B.ln) ? 1 : (A.ln == B.ln && A.fn <= B.fn) ? 1 : -1;
  if (result == -1)
    return false;
  else
    return true;
}

int main() {
  string s;
  vector<Name> Names;
  getline(cin, s);
  while (s.size() > 0) {
    vector<string> name;
    name = split(s, ' ');
    Name n;
    n.fn = name[0];
    n.ln = name[1];
    n.full = false;
    Names.push_back(n);
    getline(cin, s);
  }
  sort(Names.begin(), Names.end(), compare);
  int len = Names.size();
  FOR(i, 0, len - 1) {
    FOR(j, i + 1, len - 1) {
      if (Names[i].fn == Names[j].fn) {
        Names[i].full = true;
        Names[j].full = true;
      }
    }
  }
  for (auto i = Names.begin(); i != Names.end(); ++i) {
    if (i->full)
      cout << i->fn << " " << i->ln << endl;
    else
      cout << i->fn << endl;
  }
}
