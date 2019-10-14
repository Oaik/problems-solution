#include <bits/stdc++.h>
#define ll    long long

using namespace std;
const int N = 1e2 + 9;

void debug() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
	#endif
}

char arr[N];

int main() {
	debug();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	bool can = 0;
	for (int i = 0; i <= n; ++i) {
		int total = i;
		can = 1;
		for (int j = 1; j <= n; ++j) {
			if(arr[j] == '-')
				--total;
			else
				++total;
			if(total < 0) {
				can = 0;
				break;
			}
		}
		if(can) {
			cout << total;
			return 0;
		}
	}
	return 0;
}
