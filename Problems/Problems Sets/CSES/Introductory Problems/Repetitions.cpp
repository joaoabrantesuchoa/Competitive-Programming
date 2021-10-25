
#include <bits/stdc++.h>

using namespace std;

string s;
int number = 1;
int bigger_number = 1;


int main() {
	cin >> s;

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) {
			number++;
			bigger_number = max(bigger_number, number);
		} else {
			number = 1;
		}
	}
	cout << bigger_number << "\n";



	return 0;
}