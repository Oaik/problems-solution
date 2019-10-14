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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int q, n;
	string str;
	cin >> q;
	while(q--) {
		cin >> n;
		cin >> str;
		if(str.length() == 2) {
			if(str[0] - '0' < str[1] - '0') {
				cout << "YES\n2\n";
				cout << str[0] << " " << str[1] << "\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "YES\n2\n";
			cout << str[0] << " " << str.substr(1) << "\n";
		}
	}
	return 0;
}
