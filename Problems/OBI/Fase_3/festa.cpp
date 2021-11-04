#include <bits/stdc++.h>

using namespace std;


int arr[4000009];
int n,m, t;


int main() {
	cin >> n >> m;
	int puxoes = 0;
	while(m--) {
		cin >> t;
		for (int i = t + puxoes; i < n; i += t) {
			arr[i] = -1;
		}
		puxoes++;
	}
	for(int i = 0; i < n; i++) {
		if (arr[i] != -1) cout << i + 1 << "\n";
	}


}