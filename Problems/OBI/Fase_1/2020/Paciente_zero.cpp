#include <bits/stdc++.h>

using namespace std;

int n,c,p,i;
int contamined;
bool infected[1500];

int main() {
    cin >> n >> c;

    for (int j = 0; j < c; j++) {
        cin >> p >> i;

        for (int k = 0; k < i; k++) {
            cin >> contamined;
            infected[contamined] = true;
        }
    }

    for (int j = 1; j <= n; j++) {
        if (infected[j] == false) {
            cout << j << "\n";
        }
    }

    return 0;
}