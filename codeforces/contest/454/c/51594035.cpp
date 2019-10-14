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

ll arr[N];

int power(int x, unsigned int y) {
    int res = 1;

    while (y > 0) {
        if (y & 1)
            res = res*x;

        y = y>>1;
        x = x*x;
    }
    return res;
}

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, m, a = 0;
	double ans = 0, x = 0, y = 0;
//	ll total = 0;
	cin >> n >> m;
//	ll allComb = power(n, m);
	for (int i = 1; i <= n; ++i) {
		ll b = power(i, m);
		x = (double)i/n;
		x = pow(x, m);
//		arr[i] = b-a;
		ans += i*(x-y);
		y = x;
	}
//	for (int i = 1; i < 7; ++i) {
//		cout << arr[i] << endl;
//	}
	cout << ans;
//	cout << (double)total/allComb;
}
