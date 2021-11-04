#include <bits/stdc++.h>

using namespace std;

int n,k,u, number;
vector<unordered_set<int>> bingo(1200);

vector<int> play (int number) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bingo[i].erase(number);
        if (bingo[i].empty()) {
            ans.push_back(i + 1);
        }
    }
    return ans;
} 

int main() {

    cin >> n >> k >> u;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> number;
            bingo[i].insert(number);
        }
    }

    for (int i = 0; i < u; i++) {
        cin >> number;
        vector<int> winners = play(number);
        if (winners.size() != 0) {
            for (int j : winners) {
                cout << j << " ";
            }
            cout << "\n";
            break; 
        }
    }

    return 0;
}