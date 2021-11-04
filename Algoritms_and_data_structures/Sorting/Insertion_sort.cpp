#include <bits/stdc++.h>

using namespace std;

int n, value;
vector<int> arr;

vector<int> insertion_sort(vector<int> arr) {
	for (int i = 1; i < arr.size(); i++) {
		int key_pos = i;
		while(key_pos > 0 && arr[key_pos] < arr[key_pos - 1]) {
			int aux = arr[key_pos];
			arr[key_pos] = arr[key_pos -1];
			arr[key_pos -1] = aux;
			key_pos--;	
		}
	}
	return arr;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> value;
		arr.push_back(value);
	}
	arr = insertion_sort(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}