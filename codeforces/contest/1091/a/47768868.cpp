#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int y,b,r;
	cin >> y >> b >> r;
	int x = min(y, min(b - 1, r - 2));
	cout << x * 3 + 3;
	return 0;
}
