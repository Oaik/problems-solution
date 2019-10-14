#include <iostream>
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
	for (int j = 0; j < n - 1; ++j) {
		if (arr1[j] < arr1[j + 1]) {
			cout << "unrated";
			return 0;
		}

	}
	cout << "maybe";
	return 0;
}
