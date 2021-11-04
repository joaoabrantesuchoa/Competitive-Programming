#include <bits/stdc++.h>

using namespace std;

int m,a,b;


int main() {

	cin >> m >> a >> b;
	
	int old = max(m - a - b, a);
	old = max(old, b);

	cout << old  << "\n";

	return 0;
}
