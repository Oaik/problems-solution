#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool arr[100001];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, a;
	bool player = true; // false -> player 1
	cin >> n;
	arr[0] = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		player = arr[i-1];
		while(a > 1) {
			if (a % 2 == 0 && a != 2) {
				a /= 2;
				if(a % 2 != 0)
					player = !player;
			} else {
				a -= 1;
				player = !player;
			}
		}
		if (player)
			cout << 2 << "\n";
		else
			cout << 1 << "\n";
		arr[i] = player;
	}
}
