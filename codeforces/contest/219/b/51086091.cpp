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

int count9(string str) {
	int n9 = 0, n = str.length();
	for (int i = n-1; i >= 0; --i) {
		if(str[i] == '9')
			++n9;
		else
			break;
	}
	return n9;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	// corner case 999
	ll n, m, i = 0, cnt = 0, n9 = 0, mm = 0;
	string str;
	cin >> str >> m;
	ll ans = stoll(str);
	n9 = count9(str);
//	cnt = ans;
	i = str.length();
	int j = 1;
	while(j < i) {
		string qq = str.substr(j);
		ll req = stoll(qq) + 1;
		if(req <= m) {
			string oo = to_string(ans - req);
			if(count9(oo) > n9) {
				n9 = count9(oo);
				cnt = req;
			}
		}
		++j;
	}
	if(cnt != 0)
		cout << ans - cnt;
	else
		cout << ans;

	return 0;
}
