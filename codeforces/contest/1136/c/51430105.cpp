#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
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

int const N = 5e2 + 9, M = 100 + 9, OO = 1e9;

int arr[N][N], arr2[N][N];
vector<vector<int>> vec(N+N), vec2(N+N);

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			vec[i+j].push_back(arr[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr2[i][j];
			vec2[i+j].push_back(arr2[i][j]);
		}
	}
	for (int i = 0; i < N+N; ++i) {
		sort(all(vec[i]));
		sort(all(vec2[i]));
		if(vec[i] != vec2[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
