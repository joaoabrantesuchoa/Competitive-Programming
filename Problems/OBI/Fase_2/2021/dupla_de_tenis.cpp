#include <bits/stdc++.h>

using namespace std;

long a,b,c,d;
long sums1[6];
long sums2[6];

int main() {
	cin >> a >> b >> c >> d;

	sums1[0] = a + b;
	sums1[1] = a + c;
	sums1[2] = a + d;
	sums1[3] = b + c;
	sums1[4] = b + d;
	sums1[5] = c + d;

	sums2[0] = c + d;
	sums2[1] = b + d;
	sums2[2] = b + c;
	sums2[3] = a + d;
	sums2[4] = a + c;
	sums2[5] = a + b;

	long answer = 1000000000;

	for (int i = 0; i < 6; i++) {
		answer = min(answer, abs(sums1[i] - sums2[i]));
	}
	cout << answer << "\n";

}