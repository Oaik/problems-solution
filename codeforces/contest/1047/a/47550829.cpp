#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	if((n-2) % 3 != 0) {
		cout << n-2 << " " << 1 << " " << 1 << " ";
	} else {
		cout << n-3 << " " << 2 << " " << 1 << " ";
	}
}
