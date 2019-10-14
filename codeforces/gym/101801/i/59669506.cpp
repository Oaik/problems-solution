#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
#define PI		acos(-1)
void yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
#endif
//	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 9, M = 5e5 + 74, OO = 0x3f3f3f3f;
ll MOD = (ll) 1e9 + 7;
ll fastPow(ll x, ll y) {
	ll res = 1;
	x = x % MOD;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % MOD;
		y = y >> 1;
		x = (x * x) % MOD;
	}
	return res % MOD;
}
int cum[N];
int main() {
	yahia74();
	int t, N, Q, a, l, r, idx;
	ll val;
	cin >> t;
	while (t--) {
		cin >> N >> Q;
		clr(cum, 0);
		val = 0;
		for (int i = 1; i <= N; i++) {
			cin >> a;
			cum[i] = cum[i - 1] + a % 2;
		}
		for (int i = 0; i < Q; ++i) {
			cin >> l >> r >> idx;
			if (idx) {
				if (cum[r] == 0)
					cout << 0 << el;
				else
					cout << fastPow(2, cum[r] - cum[l - 1]) - 1 << el;
			} else {
//				else {
//					ll x = (fastPow(2, r - l + 1) - 1), y = (fastPow(2,
//							cum[r] - cum[l - 1]) - 1);
//					cout << r - l + 1 << el;
//					cout<<x<<" "<<y<<el;
				val = (fastPow(2, r - l + 1) - fastPow(2, cum[r] - cum[l - 1]));
				val = ((val % MOD) + MOD) % MOD;
				cout << val << el;
//				}
			}
		}
	}
	return 0;
}
