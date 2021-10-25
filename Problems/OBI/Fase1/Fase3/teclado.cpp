#include <bits/stdc++.h>

using namespace std;

string n, c;
int m;
map<char, string> mapa;

bool possui(string n, string c) {
	if (n.length() != c.length()) return false;
	for (int i = 0; i < n.length(); i++) {
		string letras = mapa[n[i]];
		if (letras.find(c[i]) == std::string::npos) {
			return false;
		}
	}
	return true;
}

int main() {
	mapa.insert(pair<char, string>('2', "abc"));
	mapa.insert(pair<char, string>('3', "def"));
	mapa.insert(pair<char, string>('4',"ghi"));
	mapa.insert(pair<char, string>('5', "jkl"));
	mapa.insert(pair<char, string>('6', "mno"));
	mapa.insert(pair<char, string>('7', "pqrs"));
	mapa.insert(pair<char, string>('8', "tuv"));
	mapa.insert(pair<char, string>('9', "wxyz"));

	cin >> n >> m;
	int ans = 0;
	while(m--) {
		cin >> c;
		if (possui(n, c)) ans++;
	}
	cout << ans << "\n";

	return 0;
}