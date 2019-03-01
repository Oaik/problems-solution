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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int arr[101];

int main() {
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	double d, cb, ratio = (1/3);
	ll real, r, rr;
	ratio = (double)1/(double)3;
	while(cin >> d, d) {
		real = cbrt(d);
		r = real * real;
		rr = real * real * real;
		cb = ratio * (d - rr);
		cb = (cb/(double)r);
		cout << real + cb << endl;
	}
}

