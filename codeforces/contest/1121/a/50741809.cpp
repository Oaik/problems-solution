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
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int arr[191], arr2[191], strongest[191];

vector<pair<int, int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr2[i];
	}
	for (int i = 0; i < n; ++i) {
//		vec.push_back({arr2[i], arr[i]});
		strongest[arr2[i]] = max(strongest[arr2[i]], arr[i]);
	}
	int nums = 0, a;
	for (int i = 0; i < q; ++i) {
		cin >> a;
		--a;
		if(arr[a] != strongest[arr2[a]])
			++nums;
	}
	cout << nums;
}
