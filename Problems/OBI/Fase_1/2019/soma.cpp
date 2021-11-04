#include <bits/stdc++.h>

using namespace std;

int n,k;
long long ans = 0;
long long prefix_sum[500009] = {0};
long long arr[500009];

//Solution in O(Nlog N). Make a binary search in each index of the prefix sum to find
//The position x whose sum from I to X == K.
//For the 0 values, we save the the last moment when the sum change
//and subtract the diferrence between the position we find the Sum == K and the last moment the sum change.

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	prefix_sum[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];

	}

	for (int i = 1; i <= n; i++) {
		int resp = upper_bound(prefix_sum + i, prefix_sum + n + 1, prefix_sum[i - 1] + k) - lower_bound(prefix_sum + i, prefix_sum + n + 1, prefix_sum[i - 1] + k);
		ans += resp;
	}
	cout << ans << "\n";
	return 0;
}
