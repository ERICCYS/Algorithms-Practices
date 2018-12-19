#include<bits/stdc++.h>
using namespace std;

void print_deck(vector<int> deck) {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i] << " ";
    }
    cout << endl;
}
bool origin(vector<int> deck) {
    for (int i = 0; i < deck.size(); i++) {
        if (deck[i] != i) {
            return false;
        }
    }
    return true;
}
vector<int> out_shuffle(vector<int> deck) {
    vector<int> new_deck;
    for (int i = 0; i < (deck.size())/2; i++) {
        new_deck.push_back(deck[i]);
        new_deck.push_back(deck[i + (deck.size()+1)/2]);
    }
    if (deck.size() % 2 == 1) {
        new_deck.push_back(deck[deck.size()/2]);
    }
    return new_deck;
}

vector<int> in_shuffle(vector<int> deck) {
    vector<int> new_deck;
    if (deck.size() % 2 == 1) {
        for (int i = (deck.size()-1); i > (deck.size())/2; i--) {
            new_deck.push_back(deck[i]);
            new_deck.push_back(deck[i - (deck.size()+1)/2]);
        }
        new_deck.push_back(deck[(deck.size())/2]);
    } else {
        for (int i = (deck.size()/2 - 1); i >= 0; i--) {
            new_deck.push_back(deck[i]);
            new_deck.push_back(deck[i + (deck.size()+1)/2]);
        }
    }
    reverse(new_deck.begin(), new_deck.end());
    return new_deck;
}

int main() {
    int s;
    string m;
    cin >> s;
    cin >> m;
    if (s == 1) {
        cout << 1;
        return 0;
    }
    vector<int> deck;
    for(int i = 0; i < s; i++) {
        deck.push_back(i);
    }

    int t = 1;
    if (m == "out") {
        deck = out_shuffle(deck);
        // print_deck(deck);
        while (!origin(deck)) {
            deck = out_shuffle(deck);
            // print_deck(deck);
            t++;
        }
        cout << t;
    } else if (m == "in") {
        deck = in_shuffle(deck);
        // print_deck(deck);
        while (!origin(deck)) {
            deck = in_shuffle(deck);
            // print_deck(deck);
            t++;
        }
        cout << t;
    }
    return 0;
}