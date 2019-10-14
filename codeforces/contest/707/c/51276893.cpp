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

vector<int> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ull n, m;
	cin >> n;
	if(n <= 2) {
		cout << -1;
		return 0;
	}
	m = (n * n) / 2;
	if ((n * n) + (m * m) == (m + 1) * (m + 1)) {
		cout << m << " " << m + 1;
		return 0;
	}
	m /= 2;
	if ((n * n) + ((m-1) * (m-1)) == (m + 1) * (m + 1)) {
		cout << m - 1 << " " << m + 1;
		return 0;
	}
	cout << -1;
}
