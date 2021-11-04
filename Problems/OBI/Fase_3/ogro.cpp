#include <bits/stdc++.h>

using namespace std;

int n;

int main() {

	cin >> n;
	string m1 = "", m2 = "";
	if (n == 0) {
		cout << "*" << "\n" << "*" << "\n";
	} else if (n <= 5) {
		for (int i = 0; i < n; i++) m1 += 'I';

		cout << m1 << "\n" << "*" << "\n";
	} else if (n > 5) {
		m1 = "IIIII";
		for (int i = 0; i < (n - 5); i++) m2 += "I";
		cout << m1 << "\n" << m2 << "\n"; 
	}
	


	return 0;
}