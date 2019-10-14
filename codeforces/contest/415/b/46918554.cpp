#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	ll num;
	ll a, b, x;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		num = (a * x) / b; // floor

		num = ceil(num * ((double)b/(double)a)); // ceil
		cout << x - num << " ";
	}
}
