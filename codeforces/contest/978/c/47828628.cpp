#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

ll rooms[200001];

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	ll a, b, idx;
	cin >> n >> m;
	rooms[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		rooms[i] = a + rooms[i-1];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b;
		--b;
		auto it = upper_bound(rooms, rooms + n, b);
		idx = it - rooms;
		cout << idx << " " << b - rooms[idx-1] + 1 << "\n";
	}
	return 0;
}
