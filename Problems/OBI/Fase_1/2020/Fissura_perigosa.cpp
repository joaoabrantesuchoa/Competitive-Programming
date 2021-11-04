#include <bits/stdc++.h>

using namespace std;

int n,f;

char adjMatrix[510][510];

int mv[4] = {1,-1,0,0};
int mh[4] = {0,0,1,-1};

bool can(int i, int j) {
    return i >= 0 && i <= n - 1 && j >= 0 && j <= n - 1 && (adjMatrix[i][j] - '0') <= f && adjMatrix[i][j] != '*';
}

void invade(int l, int c) {
    adjMatrix[l][c] = '*';
    for (int i = 0; i < 4; i++) {
        int lr = mv[i] + l;
        int cr = mh[i] + c; 
        if (can(lr,cr)) { 
            invade(lr,cr);
        }
    }
}

int main() {
    cin >> n >> f;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    if (adjMatrix[0][0]  - '0' <= f) {
        invade(0,0);   
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}