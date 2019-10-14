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

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;

int arr[101];

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, a, q;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		q = a % m;
		++arr[q];
	}
	int cnt = 0, revi, ans;
	for (int i = 0; i < m; ++i) {
		if(i == 0) {
			if(arr[i]&1) {
				cnt += arr[i] - 1;
				arr[i] = 1;
			} else {
				cnt += arr[i];
				arr[i] = 0;
			}
		} else {
			revi = m-i;
			ans = min(arr[i], arr[revi]);
			if(revi == i) {
				if(ans & 1) {
					cnt += ans - 1;
					arr[i] -= ans - 1;
				} else {
					cnt += ans;
					arr[i] -= ans;
				}
			} else {
				cnt += ans * 2;
				arr[i] -= ans, arr[revi] -= ans;
			}
		}
	}
	cout << cnt;
}
