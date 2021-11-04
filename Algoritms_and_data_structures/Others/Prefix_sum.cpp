#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000009;
long long n,q,l,r;
long long arr[MAXN], prefix_sum[MAXN];

int main() {
	cin >> n >> q;
	prefix_sum[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}

	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
	}
	return 0;
}
