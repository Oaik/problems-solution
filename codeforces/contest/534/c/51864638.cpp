#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, M = 1e6 + 9, OO = 1e9;

ll arr[N], pre[N];

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, a;
	cin >> n >> a;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		pre[i] += pre[i - 1] + arr[i];
	}
	ll d, cur = 0, sum, first, second;
	for (int i = 1; i <= n; ++i) {
		d = arr[i];
		sum = pre[n] - arr[i];
//		cur = 0;
//		for (int j = 1; j <= d; ++j) {
//			if ( j <= a - (n - 1) && a - sum <= j) {
//				++cur;
//			}
//		}
		first = min(a - (n-1), arr[i]), second = max(a - sum, 1ll);
		cout << arr[i] - (first - second + 1) << " ";
//		cout << arr[i] - cur << " ";
	}
	return 0;
}
