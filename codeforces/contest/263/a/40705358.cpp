#include <iostream>
using namespace std;

int main() {
	int count = 0;
	const int size = 5;
	int arr[size];
	for (int k = 0; k < size; ++k) {
		for (int i = 0; i < size; ++i) {
			cin >> arr[i];
			if (arr[i] == 1) {
				count = abs(2 - k);
				count += abs(2 - i);
			}
		}
	}
	cout << count;
	return 0;
}