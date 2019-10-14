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

int const N = 101, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int a, a2, a3, b, b2,b3;
	cin >> a >> b >> a2 >> b2 >> a3 >> b3;
	if((a2+a3 <= a && max(b2, b3) <= b) || (b2+b3 <= b && max(a2, a3) <= a) ) {
		cout << "YES";
		return 0;
	}
	if((a2+b3 <= a && max(b2, a3) <= b) || (b2+a3 <= b && max(a2, b3) <= a) ) {
		cout << "YES";
		return 0;
	}
	if((b2+a3 <= a && max(a2, b3) <= b) || (a2+b3 <= b && max(b2, a3) <= a) ) {
		cout << "YES";
		return 0;
	}
	if((b2+b3 <= a && max(a2, a3) <= b) || (a2+a3 <= b && max(b2, b3) <= a)) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}
