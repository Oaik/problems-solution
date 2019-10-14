#include <iostream>
using namespace std;
int main() {
	int n = 0,count = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i) {
			if (arr[i] != arr[i + 1])
				++count;
	}
	cout << count;
	return 0;
}