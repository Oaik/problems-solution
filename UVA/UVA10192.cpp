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

int const N = 1e2 + 9, M = 100 + 9, OO = 5e8 + 9;

ll n, m, mem[101][101];
string str1, str2;
ll dp(int i, int j) {
	if(i == n || j == m)
		return 0;
	ll& ret = mem[i][j];
	if(~ret)
		return ret;
	if(str1[i] == str2[j]) {
		return ret = dp(i+1, j+1) + 1;
	}
	ret = max(dp(i+1, j), dp(i, j+1));
	return ret;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t = 0;
	while(getline(cin, str1), str1[0] != '#') {
		getline(cin, str2);
		n = str1.length(), m = str2.length();
		clr(mem, -1);
		cout << "Case #" << ++t << ": you can visit at most "<< dp(0, 0) << " cities.\n";
	}
	return 0;
}

