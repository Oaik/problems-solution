#include <iostream>
using namespace std;
int arr[100];

int main() {
	int n = 0, k = 0, counter = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	counter = k;
	for (int i = k-1; i >= 0; --i) {
		if(arr[i] <= 0)
			--counter;
		else
			break;
	}
	for (int i = k; i < n && arr[k-1] > 0; ++i) {
		if(arr[i] >= arr[k-1])
			++counter;
		else
			break;
	}
	cout << counter;
	return 0;
}
