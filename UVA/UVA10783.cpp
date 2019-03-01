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
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t, a, b;
	for (int i = 1; i < 101; ++i) {
		if(i&1)
			arr[i] = i;
		arr[i] += arr[i-1];
	}
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> a >> b;
		cout << "Case " << i << ": " << arr[b] - arr[a-1] << endl;
	}
}

