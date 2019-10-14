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

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll a1, a2, a3, a4, a5, a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

	ll areaOfBigTrig = (a1 + a2 + a3) * (a1 + a2 + a3); // 1/2 * sin(60) will be just constant
	ll areaOf1st = a1 * a1, areaOf2nd = a3*a3, areaOf3rd = a5*a5; // same reason as above

	cout << areaOfBigTrig - areaOf1st - areaOf2nd - areaOf3rd;
}
