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

ll const N = 2e5 + 9, M = 50009, OO = 0x3f3f3f3f;

int indx[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, a, mx = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		indx[a] = i+1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(indx[a] - mx > 0) {
			cout << indx[a] - mx << " ";
			mx = indx[a];
		} else
			cout << "0 ";
	}
	return 0;
}
