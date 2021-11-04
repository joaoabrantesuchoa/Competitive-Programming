#include <bits/stdc++.h>

using namespace std;

int n,c,m;
int specials[150];
int buy[150];

int main() {


    cin >> n >> c >> m;

    int not_buy = c;

    for (int i = 0; i < c; i++) {
        cin >> specials[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> buy[i];
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < m; j++) {
            if (specials[i] == buy[j]) {
                not_buy--;
                break;
            }
        }
    }   

    cout << not_buy << "\n";

    return 0;
}