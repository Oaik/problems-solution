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

vector<int> vec;
int arr[N];

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, k, a;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		vec.push_back(a);
		arr[a] = i;
	}
	ll ans = 0;
	int cur;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		ans += arr[a] / k + 1;
		cur = arr[a];
		if (cur != 0) {
			--arr[a];
			++arr[vec[cur - 1]];
			swap(vec[cur], vec[cur - 1]);
		}
	}
	cout << ans;
	return 0;
}
