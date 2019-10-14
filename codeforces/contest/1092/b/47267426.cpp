#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr[101];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	n /= 2;
	for (int i = 0; i < n; ++i) {
		sum += arr[a+1] - arr[a];
		a += 2;
	}
	cout << sum;
}
