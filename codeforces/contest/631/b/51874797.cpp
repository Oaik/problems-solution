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

int const N = 5e3 + 9, M = 1e6 + 9, OO = 1e9;

int arr[N][N];

int col[N], row[N];
int colNum[N], rowNum[N];

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a >> b >> c;
		--b;
		if(a == 1) {
			row[b] = c;
			rowNum[b] = i;
//			for (int i = 0; i < m; ++i) {
//				arr[b][i] = c;
//			}
		} else {
			col[b] = c;
			colNum[b] = i;
//			for (int i = 0; i < n; ++i) {
//				arr[i][b] = c;
//			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(rowNum[i] > colNum[j]) {
				cout << row[i] << " ";
			} else if(colNum[j] > rowNum[i]) {
				cout << col[j] << " ";
			} else
				cout << "0 ";
		}
		cout << '\n';
	}
	return 0;
}
