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

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll a, b, cntA = 0, cntB = 0;
	cin >> a >> b;
	ll total = a * b;
	bool aGreater = a > b;
	if (aGreater) {
		cntA = b;
		for (ll i = b; i <= total; i += b) {
			if (i % a != 0)
				++cntB;
		}
	} else {
		cntB = a;
		for (ll i = a; i <= total; i += a) {
			if (i % b != 0)
				++cntA;
		}
	}
	if (cntA > cntB)
		printf("Dasha");
	else if (cntB > cntA)
		printf("Masha");
	else
		printf("Equal");
	return 0;
}
