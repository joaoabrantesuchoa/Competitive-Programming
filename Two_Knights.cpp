#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
	cin >> n;

	for (long long i = 1; i <= n; i++) {
		long long ans1 = i * i * (i * i - 1) / 2;
		long long ans2 = 4 * (i - 1) * (i - 2);
		cout << ans1 - ans2 << "\n"; 
	}
	return 0;
}