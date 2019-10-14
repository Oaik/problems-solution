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
int T[N], I[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int s, x1, x2, t1, t2, tram, d1, d2;
	cin >> s >> x1 >> x2 >> t1 >> t2 >> tram >> d1;
	if (x1 < x2)
		d2 = 1;
	else
		d2 = -1;
	int steps = 0;
	if (d1 == 1) {
		for (int i = tram; i <= s; ++i) {
			T[i] = (i - tram) * t1;
			++steps;
		}
		if (d2 == -1) {
			for (int j = s - 1; j >= 0; --j) {
				T[j] = (steps) * t1;
				++steps;
			}
		} else if (x1 < tram) {
			for (int j = s - 1; j >= 0; --j) {
				T[j] = (steps) * t1;
				++steps;
			}
			for (int j = 1; j <= x2; ++j) {
				T[j] = (steps) * t1;
				++steps;
			}
		}
	} else {
		for (int i = tram; i >= 0; --i) {
			T[i] = (tram - i) * t1;
			++steps;
		}
		if (d2 == 1) {
			for (int j = 1; j <= x2; ++j) {
				T[j] = (steps) * t1;
				++steps;
			}
		} else if (tram < x1) {
			for (int j = 1; j <= s; ++j) {
				T[j] = (steps) * t1;
				++steps;
			}
			for (int j = s-1; j >= 0; --j) {
				T[j] = (steps) * t1;
				++steps;
			}
		}
	}
	cout << min(T[x2], abs(x1 - x2) * t2);
	return 0;
}
