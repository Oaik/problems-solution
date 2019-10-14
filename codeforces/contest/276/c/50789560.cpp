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

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;
int arr[N], comp[N];
vector<int> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, q, l, r;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n+1, greater<int>());
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		++comp[l], --comp[r+1];
	}
	for (int i = 1; i <= n; ++i) {
		comp[i] += comp[i-1];
		vec.push_back(comp[i]);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (ll)vec[i] * arr[i];
	}
//	for (int i = 1; i <= n; ++i) {
//		sum += newArr[i] * comp[i];
//	}
	cout << sum;
}
