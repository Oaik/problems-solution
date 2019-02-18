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

int const N = 10000 + 9, M = 100 + 9, OO = 5e8 + 9;

int n, m;
int mem[N][M], arr[N];

int fix(int mod, int sum) {
	return (mod + sum % m + m) % m;
}

int dp(int i = 0, int mod = 0) {
	if (i == n)
		return (mod == 0);
	int& ret = mem[i][mod];
	if (ret != -1)
		return ret;
	return ret = dp(i + 1, (mod + arr[i]%m + m)%m) | dp(i + 1, (mod - arr[i]%m + m)%m);
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t;
	cin >> t;
	while (t--) {
		clr(mem, -1);
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		if (dp()) {
			cout << "Divisible";
		} else {
			cout << "Not divisible";
		}
		cout << "\n";
	}
	return 0;
}

