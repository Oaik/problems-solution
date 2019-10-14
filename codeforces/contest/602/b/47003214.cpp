#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr[100001] = {};

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int cnt = 0, maxNum = 0, minNum = INT_MAX, n, res = 0, k = 0, j = 0;
	bool ok = false;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		maxNum = max(maxNum, arr[i]), minNum = min(minNum, arr[i]);
		if(maxNum - minNum <= 1)
			++cnt;
	}
	if(cnt == n) {
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		cnt = 0, k = i, ok = false;
		maxNum = arr[i], minNum = arr[i];
		while(maxNum - minNum <= 1 && k != n) {
			++cnt, ++k;
			maxNum = max(maxNum, arr[k]), minNum = min(minNum, arr[k]);
			if(arr[k] == arr[k-1] && !ok)
				i = k;
			else
				ok = true;
		}
		res = max(res, cnt);
	}
	cout << res;
}
