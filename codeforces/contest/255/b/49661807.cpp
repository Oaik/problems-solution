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

ll const N = 1e5 + 9, M = N * N / 2, OO = 0x3f3f3f3f;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	ll cntY = count(str.begin(), str.end(), 'y'), cntX = count(str.begin(), str.end(), 'x'), lps;
	if(cntY == cntX) {
		cout << "";
	} else if (cntY > cntX) {
		lps = cntY - cntX;
		for (int i = 0; i < lps; ++i) {
			cout << 'y';
		}
	} else {
		lps = cntX - cntY;
		for (int i = 0; i < lps; ++i) {
			cout << 'x';
		}
	}
	return 0;
}
