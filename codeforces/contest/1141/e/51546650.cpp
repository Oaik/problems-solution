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

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;

ll arr[N], pre[N];

ull bin(ull total, ull g, ull h) {
	ull hi = h + 9, lo = 1, mid;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		if(mid*total + g >= h)
			hi = mid-1;
		else
			lo = mid+1;
	}
	return hi;
}

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, a, hh;
	ull h;
	cin >> h >> n;
	hh =h;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		arr[i] = -a;
	}
	for (int i = 1; i <= n; ++i) {
		pre[i] += pre[i-1] + arr[i-1];
		if(pre[i] >= hh) {
			cout << i;
			return 0;
		}
	}
	ll total = pre[n];
	if(total <= 0) {
		cout << -1;
		return 0;
	}

	ull res = 0, mn = 2e18;
	for (int i = 1; i <= n; ++i) {
		// binary search on 1 to k
		ull t = bin(total, pre[i], h);
//		if(total*(k-1) + pre[i] >= h) {
//			mn = min(mn, n*(k-1)+i);
//			continue;
//		}
		if(total * (t+1) + pre[i] >= h)
			mn = min(mn, n*(t+1) + i);
		if(total * (t) + pre[i] >= h)
			mn = min(mn, n*t + i);
		if(total * (t-1) + pre[i] >= h)
			mn = min(mn, n*(t-1) + i);
	}
	cout << mn;
}
