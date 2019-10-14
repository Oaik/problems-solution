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

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll a, b;
	cin >> a >> b;
	if(a == 1 && b == 1) {
		cout << 1;
		return 0;
	}
	ll cnt = 0;
	ll mxNum = max(a, b), mnNum = min(a, b), num;
	while(a != 1 && b != 1) {
		mxNum = max(a, b), mnNum = min(a, b);
		num = mxNum / mnNum;
		cnt += num;
		mxNum -= num * mnNum;
		a = mxNum, b = mnNum;
	}
	cout << cnt + max(mxNum, mnNum);
}
