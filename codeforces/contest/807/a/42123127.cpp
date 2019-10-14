#include <bits/stdc++.h>
using namespace std;

int arr1[1000], arr2[1000];

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i] >> arr2[i];
		if (arr1[i] != arr2[i]) {
			cout << "rated";
			return 0;
		}
	}
	for (int j = 0; j < n; ++j) {
		for (int i = j+1; i < n; ++i) {
			if (arr1[j] < arr1[i]) {
				cout << "unrated";
				return 0;
			}
		}
	}
	cout << "maybe";
	return 0;
}
