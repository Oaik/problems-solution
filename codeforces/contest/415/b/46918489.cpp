#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	ll num;
	double a, b, x;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		num = (a * x) / b; // floor

		num = ceil(num * (b/a)); // ceil
		cout << x - num << " ";
	}
}
