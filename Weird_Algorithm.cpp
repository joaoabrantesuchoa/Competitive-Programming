#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
	cin >> n;

	while(n != 1) {
		cout << n << " ";

		if (n % 2 == 0) {
			n /= 2;
		} else {
			n *= 3;
			n++;
		}
	}

	cout << n << "\n";


	return 0;
}