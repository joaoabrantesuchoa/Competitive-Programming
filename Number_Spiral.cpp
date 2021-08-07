#include <bits/stdc++.h>

using namespace std;

int t;
int main() {
	cin >> t;

	while(t--) {
		long long l, c;
		long long ans = 0;
		long long z, z2;
		cin >> l >> c;

		z = max(l , c);
		z2 = (z - 1) * (z - 1);

		if (z % 2 == 0) {
			if (z == c) ans = z2 + l;
			else ans = z2 + 2 * z - c;
		} else {
			if (l == z) ans = z2 + c;
			else ans = z2 + 2 * z - l;
		}
		cout << ans << "\n";
	}
	return 0;
}