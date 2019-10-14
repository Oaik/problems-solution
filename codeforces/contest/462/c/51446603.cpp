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

int const N = 3e5 + 9, M = 100 + 9, OO = 1e9;

ll arr[N], cum[N];

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	arr[0] = 0;
	ll sum = 0, fixSum = 0;
//	clr(cum, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	fixSum = sum;
//	sum = 0;
	sort(arr, arr+n+1);
	for (int i = 1; i <= n; ++i) {
		cum[i] += cum[i-1] + arr[i];
	}
	for (int i = 0; i < n; ++i) {
		sum += cum[n] - cum[i];
	}
	cout << sum - arr[n];
}
