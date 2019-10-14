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

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll t, n, a, b, total = 0;

	cin >> t;
	while(t--) {
		total = 0;
		cin >> n >> a >> b;
		if(n == 1) {
			cout << a << "\n";
			continue;
		}
		bool can = ( (a*2) > b );
		if(n % 2 == 0) {
			if(can) {
				total = (n/2)*b;
			} else {
				total = n * a;
			}
		} else {
			if(can) {
				total = (n/2)*b + a;
			} else {
				total = n * a;
			}
		}
		cout << total << "\n";
	}
	return 0;
}
