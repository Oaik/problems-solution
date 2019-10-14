#include <bits/stdc++.h>
#define ll    long long

using namespace std;
const int N = 5e2 + 9;

int arr[N];

void debug() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(15);
//	#ifndef ONLINE_JUDGE
//		freopen("input.txt", "rt", stdin);
//	#endif
}

int main() {
	debug();
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	double ans = 0, cur = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a = arr[a-1];
		b = arr[b-1];
		cur = a + b;
		cur = cur / (double) c;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
