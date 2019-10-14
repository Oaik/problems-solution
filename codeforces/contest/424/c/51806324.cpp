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

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;

int Xor[N];

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, ans = 0, a;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		Xor[i] = Xor[i-1] ^ i;
		cin >> a;
		ans ^= a;
	}
	for (int i = 1; i <= n; ++i) {
		int rem = n % i, numOfCyc = n/i;
		if(numOfCyc & 1)
			ans ^= Xor[i-1] ^ Xor[rem];
		else
			ans ^= Xor[rem];
	}
	cout << ans;
	return 0;
}
