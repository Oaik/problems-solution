#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> gx;
vector<int> hx;
vector<int> fx;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
	int t, j, n, m, a, i;
	cin >> t;
	while (t--) {
		j = 0;
		gx.clear();
		fx.clear();
		hx.clear();
		cin >> m;
		for (i = 0; i < m; ++i) {
			cin >> a;
			gx.push_back(a);
		}
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a;
			hx.push_back(a);
		}
		int q = n - m + 1;
		cout << q << "\n";
		int z = 0;
		for (i = 0; i < q; ++i) {
			z = 0;
			for (int j = 0; j < i; ++j) {
				z = i - j;
				if (z < m)
					hx[i] -= gx[z] * fx[j];
			}
			fx.push_back(hx[i] / gx[0]);
		}
		for (auto ff : fx) {
			cout << ff << " ";
		}
		cout << "\n";
	}
}
