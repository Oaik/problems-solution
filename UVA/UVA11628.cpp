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

int const N = 1e4 + 9, M = 100 + 9, OO = 1e9;

int arr[N];

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, a;
	ll sum = 0;
	while(cin >> n >> m, n && m) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a;
			}
			arr[i] = a, sum += a;
		}
		ll g;
		for (int i = 0; i < n; ++i) {
			if(arr[i] == 0) {
				cout << "0 / 1\n";
			} else {
				g = __gcd(sum, (ll)arr[i]);
				cout << arr[i]/g << " / " << sum/g << '\n';
			}
		}
	}
}

