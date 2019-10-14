#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(arr, k) (memset(arr, k, sizeof(arr)))
#define ll long long

using namespace std;

int arr[20];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int cnt = 0, minNum = INT_MAX, maxNum = 0, sum = 0, answer = 0;
	for (int i = 1; i < (1 << n); ++i) {
		sum = 0, minNum = INT_MAX, maxNum = 0, cnt = 0;
		for (int j = 0; j < n; ++j) {
			if(i & (1<<j)) {
				sum += arr[j], minNum = min(minNum, arr[j]), maxNum = max(maxNum, arr[j]), ++cnt;
			}
		}
		if( cnt >= 2 && sum >= l && sum <= r && maxNum - minNum >= x)
			++answer;
	}
	cout << answer;
	return 0;
}
