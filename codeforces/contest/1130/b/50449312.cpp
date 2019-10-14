#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
	//freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

ll arr[N], arr2[N], mem[N];
int n, a;

ll dp(ll i = 1) {
	if (i == n + 1)
		return 0;
	ll& ret = mem[i];
	if (~ret)
		return ret;

	ll c1 = abs(arr[i - 1] - arr[i]) + abs(arr2[i - 1] - arr2[i]) + dp(i + 1);
	ll c2 = abs(arr[i - 1] - arr2[i]) + abs(arr2[i - 1] - arr[i]) + dp(i + 1);

	return ret = min(c1, c2);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	cin >> n;
	int m = n * 2;
	for (int i = 1; i <= m; ++i) {
		cin >> a;
		if (arr[a] == 0)
			arr[a] = i;
		else
			arr2[a] = i;
	}
	clr(mem, -1);

	cout << dp() - 2;
	return 0;
}
