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

int const N = 1e4 + 2, M = 100 + 9, OO = 5e8 + 9;

int W[N], L[N], mem[N][N];
int n, a, b;

int dp(int i = 0, int mxLoad = 1e4) {
	if(i == n)
		return 0;
	int& ret = mem[i][mxLoad];
	if(~ret)
		return ret;
	int c1 = dp(i+1, mxLoad);
	int c2 = 0;
	if(W[i] <= mxLoad)
		c2 = dp(i+1, min(mxLoad - W[i], L[i])) + 1;
	return ret = max(c1, c2);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	while(cin >> n, n) {
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			W[i] = a, L[i] = b;
		}
		clr(mem, -1);
		cout << dp() << "\n";
	}
	return 0;
}

