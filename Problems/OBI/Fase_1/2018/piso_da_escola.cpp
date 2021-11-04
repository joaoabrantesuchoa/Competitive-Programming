#include <bits/stdc++.h>

using namespace std;

int t1,t2;
int l,c;

int main() {
    cin >> l >> c;

    t2 = (l - 1) * 2 + (c - 1) * 2;
    t1 = c * l + (l - 1) * (c - 1);

    cout << t1 << "\n" << t2 << "\n";

    return 0;
}