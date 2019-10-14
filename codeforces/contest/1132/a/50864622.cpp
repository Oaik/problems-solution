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

int const N = 300009, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll r = 0, l = 0;
	ll a,b,c ,d;
	cin >> a >> b >> c >> d;
	l = (a*2) + b + c;
	r = b + c + (d*2);
	if(l == r && ((c >= 1 && a >= 1 && d >= 1) || c == 0)) {
		cout << 1 << endl;
	} else
		cout << 0 << endl;
}

/*
 *
 * #include <bits/stdc++.h>

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

int const N = 300009, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll r = 0, l = 0;
	ll a,b,c ,d;
	cin >> a >> b >> c >> d;
	l = (a*2) + b + c;
	r = b + c + (d*2);
	if(l == r ) {
		if(c >= 1) {
			if(a >= 1 && d >= 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	} else
		cout << 0 << endl;
}
 *
 *
 */
