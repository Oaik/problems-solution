#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100];
int n, j = 0, temp = 0, maxCount = 0, counter = 0;

int main() {

	cin >> n;
	if (n == 1) {
		cout << "YES";
		return 0;
	}
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i) { // 1 2 1 temp 1
		counter = (count(arr, arr+n, arr[i]));
		maxCount = max(maxCount, counter);
	}
	if (maxCount <= (n+1)/2)
		cout << "YES";
	else cout << "NO";
}
