#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}


int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	// [] t {}
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a, cnt = 0;
	bool found = false;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(a == 1) {
			if(found) {
				++cnt;
			} else {
				cnt += 2;
			}
			found = true;
		} else {
			found = false;
		}
	}
	cout << max(cnt-1, 0);
}
