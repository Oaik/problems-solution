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

int primeF(int n) {
	if(n == 1)
		return 0;
	set<int> s;
	for (ll i = 2; i*i <= n; ++i) {
		while(n % i == 0) {
			s.insert(i);
			n/=i;
		}
	}
	if(n > 1)
		s.insert(n);
	return s.size();
}

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	while(cin >> n, n) {
		int res = primeF(n);
		cout << n << " : " << res << '\n';
	}
}

