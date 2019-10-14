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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

map<ll, int> mp;
map<ll, bool> mpa;
int arr[N];

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		arr[i] = a;
		++mp[a];
	}
	sort(arr, arr+n);
	ll sum = 0, b;
	for (int i = 0; i < n; ++i) {
		a = arr[i];
		b = (ll)a*m;
		if(!mp[b]) {
			sum += mp[a];
			mpa[a] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		a = arr[i];
		if(mpa[a])
			continue;
		if(!mpa[a*m]) {
			mpa[a*m] = 1;
			sum += mp[a];
		}
	}
	cout << sum;
}
