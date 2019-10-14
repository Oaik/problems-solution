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

int const N = 1e6 + 9, M = 1e6 + 9, OO = 1e9;

bool isPrime[N];

void sieve() {
	ll mx = 1e6 + 9;
	isPrime[0] = isPrime[1] = 1;
	for (ll i = 2; i * i < mx; ++i) {
		if(!isPrime[i]) {
			for (ll j = i*i; j < mx; j += i) {
				isPrime[j] = 1;
			}
		}
	}
}

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	sieve();
	int n;
	ll d, sq;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d;
		sq = sqrt(d);
		if(sq * sq == d)
			if(!isPrime[sq]) {
				cout << "YES\n";
				continue;
			}
		cout << "NO\n";
	}
	return 0;
}
