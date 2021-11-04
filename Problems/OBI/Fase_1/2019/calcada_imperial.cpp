#include <bits/stdc++.h>

using namespace std;

int n;
int arr[510];
int ans = 0;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int X = arr[i];
            int Y = arr[j];
            int last = -1;
            int temp = 0;
            for (int k = 1; k <= n; k++) {
                if (arr[k] != X && arr[k] != Y || arr[k] == last) continue;
                temp++;
                last = arr[k];
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << "\n";

    return 0;
}