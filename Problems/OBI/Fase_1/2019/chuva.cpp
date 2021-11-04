#include <bits/stdc++.h>

using namespace std;

int n,m;
char matrix[510][510];

bool can(int i, int j) {
	return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1 && matrix[i][j] == '.';
}

void dfs(int i, int j) {
	if(matrix[i + 1][j] == '#') {
		if (can(i, j + 1)) {
			matrix[i][j + 1] = 'o';
			dfs(i, j + 1);
		}
		if (can(i, j - 1)) {
			matrix[i][j - 1] = 'o';
			dfs(i, j - 1);
		}

	} else {
		if (can(i + 1, j)) {
			matrix[i + 1][j] = 'o';
			dfs(i + 1, j);
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		if (matrix[0][i] == 'o') {
			dfs(0,i);
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
		}
		cout << "\n";
	}

	return 0;
}
