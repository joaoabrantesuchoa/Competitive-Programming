#include <bits/stdc++.h>

using namespace std;

int n;
bool exits[200009];

int main() {
	cin >> n;
	int number;
	for (int i = 0; i < n; i++) {
		cin >> number;
		exits[number] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (exits[i] == false) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}