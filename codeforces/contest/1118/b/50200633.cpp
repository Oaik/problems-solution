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

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;

ll arr[200009], even[200009], odd[200009];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	ll a, evens = 0, odds = 0, total = 0, evensRev = 0, oddsRev = 0;
	cin >> n;
	int evenidx = 1, oddidx = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (i % 2 == 0) {
			even[i] = arr[i];
		} else {
			odd[i] = arr[i];
		}
		if(i) {
			even[i] += even[i-1];
			odd[i] += odd[i-1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		evens = even[i-1] + odd[n] - odd[i];
		odds = odd[i-1] + even[n] - even[i];
		if (evens == odds)
			++total;
	}
	cout << total;
	return 0;
}
