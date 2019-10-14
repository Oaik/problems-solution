#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[100];
	int n = 0, coins = 0,coinsAc = 0, curr = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	for (int j = 0; j < n; ++j) {
		curr += arr[j];
		++coins;
		if (curr > sum - curr)
			break;
	}
	curr = 0;
	for (int j = n-1; j >= 0; --j) {
			curr += arr[j];
			++coinsAc;
			if (curr > sum - curr)
				break;
		}
	cout << min(coins, coinsAc);
}
