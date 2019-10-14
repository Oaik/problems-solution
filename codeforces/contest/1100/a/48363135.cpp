#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

int arr[101];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k, s = 0, e = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if(arr[i] == 1)
			++s;
		else
			++e;
	}
	int re = e, rs = s, res = 0;
	for (int i = 0; i < k; ++i) {
		e = re, s = rs;
		for (int j = i; j < n; j += k) {
			if(arr[j] == 1) {
				--s;

			}
			else {
				--e;

			}
		}
		res = max(res, abs(s-e));
	}
	cout << res;
}
