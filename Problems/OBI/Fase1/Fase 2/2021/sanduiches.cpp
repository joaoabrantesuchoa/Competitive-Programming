#include <bits/stdc++.h>

using namespace std;

long long n,m,x,y;
long long total = 0;
vector<pair<long long, long long>> notGood;


void Combination(long long a[], int reqLen, int start, int currLen, bool check[], int len) 
{
	if(currLen > reqLen) return;
	else if (currLen == reqLen) {
		unordered_set<long long> conjunto;
		for (int i = 0; i < len; i++) 
		{
			if (check[i] == true) 
			{
				conjunto.insert(a[i]);
			}
		}
		for (int i = 0; i < m; i++) {
			if (conjunto.find(notGood[i].first) != conjunto.end() && conjunto.find(notGood[i].second) != conjunto.end()) {
				total--;
				break;
			} 
		}
		return;
	}
	if (start == len) 
	{
		return;
	}
	check[start] = true;
	Combination(a, reqLen, start + 1, currLen + 1, check, len);
	check[start] = false;
	Combination(a, reqLen, start + 1, currLen, check, len);
}




long long fact(long long j) {
	long long resp = 1;
	for (int g = 2; g <= j; g++) {
		resp *= g;
	}
	return resp;
}

long long combination(long long number, long long k) {
	return fact(number) / (fact(k) * fact(number - k));
}

int main() {
	cin >> n >> m;
	long long arr[n];
	bool check[n];
	for (int i = 1; i <= n; i++) {
		total += combination(n,i);
		arr[i - 1] = i;
		check[i - 1] = false;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		notGood.push_back({x,y});
	}

	for(int i = 1; i <= n; i++) {
		Combination(arr, i, 0, 0, check, n);
	}
	cout << total << "\n";

	return 0;
}