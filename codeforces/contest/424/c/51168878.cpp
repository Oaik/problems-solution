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

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;
ll F[N + 5];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, m = 1;
	for (int i = 1; i <= N; ++i)
		F[i] = F[i - 1] ^ i;

	cin >> n;
	ll res;
	res = (1 % 1);
//	for (int j = 1; j <= n; ++j) {
//		res = 0;
//		for (int i = 2; i <= j; ++i) {
//			res = res ^ (j % i);
//		}
	// the reminder is just the number j so if the reminder is odd I should xor the answer with only one j
	// otherwise xor the answer with two j
//		if((n-j) & 1) {
//			res = res ^ (j);
//		} else {
//			res = res ^ (j ^ j);
//		}
//		arr[j] = res;
//		cout << res << " ";
//	}
	for (int i = 1; i <= n; ++i) {
		int q = n / i, r = n % i;
		if (q & 1) // odd
			res ^= F[i - 1];
		res ^= F[r];
	}
	/*	At the index x: the q[x] =
	 * Even pattern: 1 0 2 1 7 3 7 2 13 7
	 * Odd pattern: 0 2 1 5 2 5 0 10 4 13
	 * I know that numbers by running brute force (which is commented above)
	 */
	ll q;
	for (int i = 1; i <= n; ++i) {
		cin >> q;
		res = (res ^ q);
	}
	cout << res;
	return 0;
}
