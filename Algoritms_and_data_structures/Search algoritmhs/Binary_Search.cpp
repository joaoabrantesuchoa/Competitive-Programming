#include <bits/stdc++.h>

using namespace std;

//This algorithm is using to find the position of an element in a order list in O(log N)
//Works this way:
//You have two bourders the low and the high. the low is on the begin of the list and the high on the end.
//You have to move these borders until you find your element. For this, guess a number whose discard the maximum
//number of elements, i.e if a want 67 and guess 50 all the 50 numbers is not gonna be discard and my low go to position 50.
//Do this until you find your objective or find it not in list.

vector<int> arr;
int n, element;

int binary_search(int objetive) {
	int low = 0;
	int high = arr.size();
	while(low < high) {
		int middle = (low + high) / 2;
		int guess = arr[middle];
		if (guess == objetive) {
			return middle;
		} else if (guess < objetive) {
			low = middle + 1;
		} else if (guess > objetive) {
			high = middle - 1;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> element;
		arr.push_back(element);	
	}
	cin >> element;
	cout << binary_search(element) << "\n";
	return 0;
}
