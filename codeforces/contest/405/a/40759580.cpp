#include <iostream>
using namespace std;
int main() {
	int col = 0;
	cin >> col;
	int arr[col];
	for (int i = 0; i < col; ++i) {
		cin >> arr[i];
	}
	for (int i = 1; i < col; ++i) {
		int copy = arr[i];
		int j = i - 1;
		while(j >= 0 && copy < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = copy;
	}
	for (int k = 0; k < col; ++k) {
		if (k == col - 1) {
			cout << arr[k];
			break;
		}
		cout << arr[k] << " ";
	}
	return 0;
}