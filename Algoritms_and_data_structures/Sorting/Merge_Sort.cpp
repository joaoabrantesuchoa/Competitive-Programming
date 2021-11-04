#include <bits/stdc++.h>

using namespace std;

int n;

void merge(int arr[], int left, int mid, int right) {
	int helper[n];

	for (int i = left; i <= right; i++) {
		helper[i] = arr[i];
	}
	int l = left; //Index of the left array
	int r = mid + 1; //Index of the right array
	int k = left; //Index of the sorted array

	while(l <= mid && r <= right) {
		if (helper[l] < helper[r]) {
			arr[k] = helper[l];
			l++;
		} else {
			arr[k] = helper[r];
			r++;
		}
		k++;
	}
	while(l <= mid) {
		arr[k] = helper[l];
		l++;
		k++;
	}
	while(r <= right) {
		arr[k] = helper[r];
		r++;
		k++;
	}
	
}

void merge_sort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	} else {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {

	cin >> n;
	int elements[n] = {};

	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	merge_sort(elements, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}

	return 0;
}