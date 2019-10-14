#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr[100001];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n,a, mx = 0, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cout << min(arr[n-1] - arr[0], min(arr[n-2] - arr[0],arr[n-1] - arr[1]));
}
